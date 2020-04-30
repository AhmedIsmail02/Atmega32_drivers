/*
 * main.c
 *
 *  Created on: Mar 26, 2020
 *      Author: Ahmed Magdy
 */
#include "StdTypes.h"
#include "Util.h"
#include "Memmap.h"
#include "DIO.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"
#include "event_groups.h"
#include <string.h>
#include "LCD_int.h"
#include "avr/delay.h"
#include "KEYPAD.h"
#define password "12345678"
char pass[9];
xSemaphoreHandle sem;
u8  place=0;
u8  k=0,count=0,flag=0;
void setup (void);

void LCD (void *para)
{
	u8 static z=0;
	while (1)
	{
		
		if(count==0)
		{
			LCD_GO_TO_X_Y(1,0);
			LCD_send_string("Password is: ");
		}

		else if(count<3 && flag==0)
		{

			
			LCD_GO_TO_X_Y(1,0);
			LCD_send_string("another pass: ");

		}


		if(count<3)
		{
			if(k==8)
			{


				if(strncmp(pass,password,strlen(password))==0)
				{
					LCD_send_cmnd(0x01);
					LCD_GO_TO_X_Y(1,0);

					LCD_send_string("Welcome ...");
					DIO_WritePin(PB,PIN3,HIGHV);
					flag=1;
				}
				else
				{

					LCD_GO_TO_X_Y(2,0);
					LCD_send_string("WRONG PASS");
					_delay_ms(200);
					LCD_send_cmnd(0X01);
					k=0;
					place=0;
					if(z==0)
					{
						z++;
						count++;


					}



				}

			}
		}
		else
		{
			LCD_GO_TO_X_Y(1,0);
			LCD_send_string("3 Wrong Passwords");
		}
		z=0;
		

		vTaskDelay(200);
	}


}
void Keypad (void *para)
{

	u8 static m=0;

	while (1)
	{
		


		u8 key=KEYPAD_GetKey();


		if(key!='/')
		{

			LCD_GO_TO_X_Y(2,place);

			LCD_send_char('*');

			if(m==0)
			{
				pass[k]=((key+1)+'0');
				k++;
				m++;
				place++;
			}



		}
		m=0;
		vTaskDelay(200);

	}


}


int main (void)
{
	setup();


	xTaskHandle key_handler;
	xTaskHandle LCD_handler;
	xTaskCreate(LCD,NULL,128,NULL,5,&LCD_handler);
	xTaskCreate(Keypad,NULL,128,NULL,1,&key_handler);
	vTaskStartScheduler();
	return 0;
}
void setup (void)
{

	DIO_SetPortDirection(PD,0xFF);
	DIO_SetPortDirection(PB,0XFF);
	LCD_init();
	LCD_send_cmnd(0x01);
}
