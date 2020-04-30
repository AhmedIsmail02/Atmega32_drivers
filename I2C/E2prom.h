/*
 * E2prom.h
 *
 *  Created on: Nov 1, 2019
 *      Author: Ahmed Magdy
 */

#ifndef E2PROM_H_
#define E2PROM_H_
void E2prom_Init(void);
u8 E2prom_write(u8 address , u8 data);
u8 E2prom_read(u8 address);

#endif /* E2PROM_H_ */
