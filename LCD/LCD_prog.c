/*
 * LCD.c
 *
 *  Created on: Sep 6, 2019
 *      Author: Ahmed Magdy
 */
#include "stdtypes.h"
#include <util/delay.h>
#include "DIO.h"
#include "LCD_PATTERNS.h"
#include "LCD_int.h"

LCD_Status LCD_send_cmnd(u8 cmnd)
{
	LCD_Status status=NOKAY;
	DIO_WritePin(LCD_CONTROL_PORT,LCD_RS_PIN,LOWV);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_RW_PIN,LOWV);
	DIO_WritePort(LCD_DATA_PORT,cmnd);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_E_PIN,HIGHV);
	_delay_ms(1);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_E_PIN,LOWV);
	status= OKAY;
	return status;
}
LCD_Status LCD_send_char(u8 data)
{
	LCD_Status status=NOKAY;
	DIO_WritePin(LCD_CONTROL_PORT,LCD_RS_PIN,HIGHV);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_RW_PIN,LOWV);
	DIO_WritePort(LCD_DATA_PORT,data);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_E_PIN,HIGHV);
	_delay_ms(1);
	DIO_WritePin(LCD_CONTROL_PORT,LCD_E_PIN,LOWV);
	status= OKAY;
	return status;
}

void LCD_init(void)
{

	 //set directions output for control pins and data pins
	 DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,OUT);
	 DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,OUT);
	 DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,OUT);
	 DIO_SetPortDirection(LCD_DATA_PORT,0XFF);
	_delay_ms(40);
	LCD_send_cmnd(CMND_FUNC_SET_CMND);
	_delay_us(40);
	LCD_send_cmnd(CMND_DISPLAY_ON_CURSOR_OFF);
	_delay_us(40);
	LCD_send_cmnd(CMND_DISPLAY_CLR);
	_delay_ms(2);
	LCD_send_cmnd(CMND_ENTRY_MODE_SET);
}
LCD_Status LCD_GO_TO_X_Y(u8 line,u8 y)

{
	LCD_Status status;
	switch (line)
	{
	case 1 :
	LCD_send_cmnd(LINE1_BASE+y);
	status=OKAY;
	break;
	case 2 :
	LCD_send_cmnd(LINE2_BASE+y);
	status=OKAY;
	break;
	default :
		status=NOKAY;
	}

	return status;

}
LCD_Status LCD_send_pattern(u8 line , u8 y)
{
	LCD_Status status=NOKAY;
	//SET add counter to CGRAM
	LCD_send_cmnd(CGRAM);
	for(u8 i=0;i<64;i++)
	{
		LCD_send_char(patterns[i]);
	}
	LCD_send_cmnd(LINE1_BASE);
	LCD_GO_TO_X_Y(line,y);
	for(u8 i=0;i<8;i++)
	{
		LCD_send_char(i);
	}
	status=OKAY;





	return status;
}
LCD_Status LCD_send_string(u8 *ptr)
{
	LCD_Status status=NOKAY;
	u8 i=0;
	while (ptr[i]!='\0')
	{

		LCD_send_char(ptr[i]);
		i++;
	}
	status = OK;
	return status;
}
