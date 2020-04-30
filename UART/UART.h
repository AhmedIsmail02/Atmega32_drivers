/*
 * UART.h
 *
 *  Created on: Oct 19, 2019
 *      Author: Ahmed Magdy
 */

#ifndef UART_H_
#define UART_H_
void UART_Init(void);
void UART_Transmit(u8 data);
u8 UART_Recieve(void);


#endif /* UART_H_ */
