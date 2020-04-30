/*
 * I2C.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Ahmed Magdy
 */

#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_
void I2C_Init();
u8 I2C_Start_Cond(u8 address);
u8 I2C_Repeted_Start_Cond(u8 address);
u8 I2C_Write(u8 data);
u8 I2C_Read_ACK();
u8 I2C_Read_NACK();
void I2C_Stop(void);
#endif /* I2C_MASTER_H_ */
