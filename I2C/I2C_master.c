/*
 * I2C.c
 *
 *  Created on: Oct 26, 2019
 *      Author: Ahmed Magdy
 */
#include "StdTypes.h"
#include "Util.h"
#include "Memmap.h"
#include "I2C_Memmap.h"
#include "DIO.h"
#include "I2C_Master.h"
void I2C_Init()
{

	TWBR=15 ; //setting the bit rate register to get SCL frequency
}
u8 I2C_Start_Cond(u8 address) //for master transmitter
{
	TWCR=(1<<TWSTA) | (1<<TWEN) | (1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	u8 status = TWSR & 248 ; //masking the status register to display only status bits
	if (status!=0x08) //means that it fails to generate start condition
		return 0;
	TWDR=address;
	TWCR=(1<<TWEN) | (1<<TWINT); //enabling the I2C And Clearing interrupt flag to start job
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	status=TWSR&248;
	if (status==0x18) //means that the address is correct and ACK received ,SLA+W Transmitted
		return 1;
	if (status==0x20) //means that the address is correct and NACK received,SLA+W Transmitted
		return 2;
	else 		//means that the address is incorrect,SLA+W not Transmitted
		return 3;
}
u8 I2C_Repeted_Start_Cond(u8 address) //for master receiver
{
	TWCR=(1<<TWSTA) | (1<<TWEN) | (1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	u8 status = TWSR & 248 ; //masking the status register to display only status bits
	if (status!=0x10) //means that it fails to generate repeated start condition
		return 0;
	TWDR=address;
	TWCR=(1<<TWEN) | (1<<TWINT); //enabling the I2C And Clearing interrupt flag to start job
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	status=TWSR&248; //masking the status register to display only status bits
	if (status==0x18)
		return 1; //means that the address is correct and ACK received ,SLA+W Transmitted
	if (status==0x20)
		return 2; //means that the address is correct and NACK received,SLA+W Transmitted
	else
		return 3; //means that the address is incorrect,SLA+W not Transmitted
}
u8 I2C_Write(u8 data)
{
	TWDR=data;
	TWCR=(1<<TWEN) | (1<<TWINT); //enabling the I2C And Clearing interrupt flag to start job
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	u8 status = TWSR&248; //masking the status register to display only status bits
	if (status==0x28)
		return 0; //means that data is transmitted and ACK is received
	if (status==0x30)
		return 1; //means that data is transmitted and NACK is received
	else
		return 2; //means that data transmission failed either due to SLA+W OR Data bytes
}
u8 I2C_Read_ACK()
{
	TWCR=(1<<TWEN) | (1<<TWINT) | (1<<TWEA); //enabling the I2C And acknowledge too
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	return TWDR;
}
u8 I2C_Read_NACK()
{
	TWCR=(1<<TWEN) | (1<<TWINT) ;//enabling the I2C And acknowledge too
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its current job
	return TWDR;
}
void I2C_Stop(void)
{
	TWCR=(1<<TWEN) | (1<<TWINT) | (1<<TWSTO) ;//enabling the I2C And acknowledge too
	while(GET_BIT(TWCR,TWINT)==0); //wait until TWI finish its stop condition job
}
