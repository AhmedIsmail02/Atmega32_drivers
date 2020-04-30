/*
 * slave.c
 *
 *  Created on: Oct 30, 2019
 *      Author: Ahmed Magdy
 */
#include "StdTypes.h"
#include "Util.h"
#include "Memmap.h"
#include "I2C_Memmap.h"
#include "DIO.h"
#include "slave.h"
void Slave_Init(u8 address)
{
	TWAR=address; //saving the address of the slave in address register
	TWCR=(1<<TWEA) | (1<<TWEN) | (1<<TWINT); //Enable TWI and ACK Generation
}
u8 Slave_listen(void)
{
	while(1)
	{
		while(GET_BIT(TWCR,TWINT)==0); //wait to be addressed
		u8 status=TWSR&248;
		if (status==0x60 || status==0x68)
			return 0; //Own SLA+W has been received, ACK has been returned
		if (status==0xA8 || status==0xB0)
			return 1; //Own SLA+R has been received, ACK has been returned
		if (status==0x70 || status==0x78)
			return 2; //General call has been received , ACK has been returned
		else
			continue;
	}
}
u8 Slave_Transmit(u8 data)
{
	TWDR=data;
	TWCR=(1<<TWEA) | (1<<TWEN) | (1<<TWINT); //Enable TWI and ACK Generation
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish its job
	u8 status=TWSR&248;
	if(status==0xA0)        // Check for STOP/REPEATED START received
	{
	    TWCR|=(1<<TWINT);    // Clear interrupt flag & return -1
	    return -1;
	}
	if (status==0xB8)
		return 0; // means that data is transmitted and ACK has been received
	if (status==0xC0)
		return -2; // means that data is transmitted and NACK has been received
	if (status==0xC8)
		return -3; // means that last data byte is transmitted and ACK has been received
	else
		return -4;
}
u8 Slave_Receive (void)
{
	TWCR=(1<<TWEA) | (1<<TWEN) | (1<<TWINT); //Enable TWI and ACK Generation
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish its job
	u8 status=TWSR&248;
	if (status==0x80 || status==90) //Check for data received &ack returned
		return TWDR;
	if (status==0x88 || status==98) //Check for data received &Nack returned
		return TWDR;
	if(status==0xA0)        /* Check wether STOP/REPEATED START */
	{
		TWCR|=(1<<TWINT);    /* Clear interrupt flag & return -1 */
	    return -1;
	}
	else
	    return -2;
}
