/*
 * E2prom.c
 *
 *  Created on: Nov 1, 2019
 *      Author: Ahmed Magdy
 */
#include "StdTypes.h"
#include "Util.h"
#include "Memmap.h"
#include "I2C_Memmap.h"
#include "DIO.h"
#include "LCD_int.h"
#include "I2C_Master.h"
#include "slave.h"
#include "E2prom.h"
void E2prom_Init(void)
{
	I2C_Init();
}
u8 E2prom_write(u8 address , u8 data)
{
	u8 status=I2C_Start_Cond(0b10100000);
	if (status==0)
	{
		LCD_send_string("Failed to generate start condition");

	}
	else if (status==1)
	{

		LCD_send_string("The address is correct and ACK received ,SLA+W Transmitted");

	}
	else if (status==2)
	{

		LCD_send_string("The address is correct and NACK received ,SLA+W Transmitted");

	}

	else if (status==3)
	{

		LCD_send_string("The address is incorrect,SLA+W not Transmitted");

	}
	u8 status1=I2C_Write(0b00000000);
	if (status1==0)
	{
		LCD_send_string("Failed to generate repeated start condition");

	}
	else if (status1==1)
	{

		LCD_send_string("The location  is correct and ACK received ,SLA+W Transmitted");

	}
	else if (status1==2)
	{

		LCD_send_string("The location is incorrect,SLA+W not Transmitted");

	}


	u8 status2=I2C_Write(0b11111111);
	if (status2==0)
	{
		LCD_send_string("The data was transmitted and ACK is received");

	}
	else if (status2==1)
	{

		LCD_send_string("The data was transmitted and NACK is received");

	}
	else if (status1==2)
	{

		LCD_send_string("data transmission failed");

	}

}
