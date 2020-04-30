/*
 * DIO.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Ahmed Magdy
 */

#ifndef DIO_H_
#define DIO_H_
#define HIGHV 1
#define LOWV 0
typedef struct  {
	u8 y;
	u8 status;
}read;
typedef enum {
	PA=0,
	PB,
	PC,
	PD
}DIOPortID_t;
typedef enum {
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIOPinID_t;
typedef enum {
	OUT=0,
	INFREE,
	INPULLUP
}DIODirection_t;
typedef enum {
	OK=0,
	NOK
}DIOStatus_t;
DIOStatus_t DIO_SetPinDirection (DIOPortID_t port ,DIOPinID_t pin,DIODirection_t dir);
DIOStatus_t DIO_SetPortDirection (DIOPortID_t port ,u8 mask);
void DIO_WritePin(DIOPortID_t port,DIOPinID_t pin,u8 value);
void DIO_WritePort(DIOPortID_t port,u8 value);
read DIO_ReadPin(DIOPortID_t port,DIOPinID_t pin);
u8 DIO_ReadPort(DIOPortID_t port);
void DIO_TogglePin(DIOPortID_t,DIOPinID_t);





#endif /* DIO_H_ */
