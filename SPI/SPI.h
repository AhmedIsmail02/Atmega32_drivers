/*
 * SPI.h
 *
 *  Created on: Oct 25, 2019
 *      Author: Ahmed Magdy
 */

#ifndef SPI_H_
#define SPI_H_
void SPI_Init(void);
u8 SPI_TRANSMITTER_AND_RECIEVE(u8 data);
void SPI_TRANSMIT_ONLY(u8 data);
u8 SPI_RECIEVE_ONLY(void);

#endif /* SPI_H_ */
