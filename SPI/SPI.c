/*
 * SPI.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Ahmed Magdy
 */
#include "StdTypes.h"
#include "Util.h"
#include "Memmap.h"
#include "SPI_Memmap.h"
#include "DIO.h"
#include "SPI.h"
void SPI_Init(void)
{
	DIO_SetPinDirection(PA,PIN0,OUT);// BOTH FIRST LINE FOR SLAVE SELECT
	DIO_WritePin(PA,PIN0,HIGHV);
	DIO_SetPinDirection(PB,PIN6,INFREE); //FOR MISO
	DIO_SetPinDirection(PB,PIN5,OUT); //FOR MOSI
	DIO_SetPinDirection(PB,PIN7,OUT); //FOR CLK
	DIO_SetPinDirection(PB,PIN4,OUT); //to avoid being slave by mistake
	//SPCR=0X00;
	SPCR=0b01010011;
}
u8 SPI_TRANSMITTER_AND_RECIEVE(u8 data)
{
	DIO_WritePin(PA,PIN0,LOWV); //to enable the shift register of slave
	SPDR=data; //send data on SPDR
	while(GET_BIT(SPSR,SPIF)==0); //waiting for an interrupt flag which means that data is transmitted
	u8 data1=SPDR;
	DIO_WritePin(PA,PIN0,HIGHV); //to make slave sleep
	return data1;
}
void SPI_TRANSMIT_ONLY(u8 data)
{
	DIO_WritePin(PA,PIN0,LOWV); //to enable the shift register of slave
	SPDR=data;
	while(GET_BIT(SPSR,SPIF)==0); //waiting for an interrupt flag which means that data is transmitted
	u8 flush_byte=SPDR; //to clear the SPIF we must do that line and the one before it
	DIO_WritePin(PA,PIN0,HIGHV); //to make slave sleep
}
u8 SPI_RECIEVE_ONLY(void)
{
	DIO_WritePin(PA,PIN0,LOWV); //to make slave awake to recieve data from it
	//now time to write dummy data to generate clock
	SPDR=0xFF;
	while(GET_BIT(SPSR,7)==0); //waiting for an interrupt flag which means that data is transmitted
	u8 data=0;
	data=SPDR;
	DIO_WritePin(PA,PIN0,HIGHV); //to make slave sleep
	return data;
}
