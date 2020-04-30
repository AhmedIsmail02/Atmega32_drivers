/*
 * UART.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Ahmed Magdy
 */
#include "stdtypes.h"
#include "Util.h"
#include <util/delay.h>
#include "Memmap.h"
#include "DIO.h"
#include"UART_Memmap.h"
#include "UART.h"
void UART_Init(void)
{

	UCSRB=0b00011000; // Enabling transmitter and receiver
	UCSRC=0b10001110; // asynchronous mode , 8-bit data , 2- stop bits
	UBRRL=51; // 8 MHz and baud rate 9600

}
void UART_Transmit(u8 data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=data;
}
u8 UART_Recieve(void)
{
	u8 data=0;
	while(GET_BIT(UCSRA,RXC)==0);
	data=UDR;
	return data;
}

