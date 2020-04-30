/*
 * I2C_Memmap.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Ahmed Magdy
 */

#ifndef I2C_MEMMAP_H_
#define I2C_MEMMAP_H_
#define TWCR (*((volatile u8*)0x56))
#define TWBR (*((volatile u8*)0x20))
#define TWSR (*((volatile u8*)0x21))
#define TWAR (*((volatile u8*)0x22))
#define TWDR (*((volatile u8*)0x23))
#define TWINT 7 /*TWI interrupt flag,The TWINT Flag must be cleared by software by writing logic
one to it. Also note that clearing this flag starts the operation of the TWI*/
#define TWEA 6 //TWI Enable Acknowledge Bit
#define TWSTA 5 /*TWSTA: TWI START Condition Bit,TWSTA must be cleared by software when
the START condition has been transmitted.*/
#define TWSTO 4 //TWSTO: TWI STOP Condition Bit
#define TWEN 2 //TWEN: TWI Enable Bit

#endif /* I2C_MEMMAP_H_ */
