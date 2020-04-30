/*
 * SPI_Memmap.h
 *
 *  Created on: Oct 25, 2019
 *      Author: Ahmed Magdy
 */

#ifndef SPI_MEMMAP_H_
#define SPI_MEMMAP_H_
#define SPCR (*((volatile u8*)0x2D))
#define SPSR (*((volatile u8*)0x2E))
#define SPDR (*((volatile u8*)0x2F))
#define SPIF 7
#endif /* SPI_MEMMAP_H_ */
