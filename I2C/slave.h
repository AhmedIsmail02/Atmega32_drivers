/*
 * slave.h
 *
 *  Created on: Oct 30, 2019
 *      Author: Ahmed Magdy
 */

#ifndef SLAVE_H_
#define SLAVE_H_
void Slave_Init(u8 address);
u8 Slave_listen(void);
u8 Slave_Transmit(u8 data);
u8 Slave_Receive (void);
#endif /* SLAVE_H_ */
