/*
 * UART_Memmap.h
 *
 *  Created on: Oct 19, 2019
 *      Author: Ahmed Magdy
 */

#ifndef UART_MEMMAP_H_
#define UART_MEMMAP_H_
#define UCSRC (*((volatile u8*)0x40))
#define UBRRH (*((volatile u8*)0x20))
#define UBRRL (*((volatile u8*)0x29))
#define UCSRA (*((volatile u8*)0x2B)) //bta3 el flags el status
#define UCSRB (*((volatile u8*)0x2A))
#define UDR (*((volatile u8*)0x2C))
#define UDRE 5
#define RXC 7

#endif /* UART_MEMMAP_H_ */
