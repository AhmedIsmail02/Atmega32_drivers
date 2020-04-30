/*
 * TIMER0.c
 *
 *  Created on: Oct 3, 2019
 *      Author: Ahmed Magdy
 */
#include "stdtypes.h"
#include "memmap.h"
#include "DIO.h"
#include "Util.h"
#include "TIMER2.h"

#include "TIMER2_memmap.h"
void TIM2_init(void)
{
	CLR_BIT(TCCR2,7); // PWM Mode
	SET_BIT(TCCR2,6); // this line and the one follow it is for configuring the pwm mode to phase correct mode
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,5); //this line and the one follow it is for configuring the pwm to set OC2 on compare match
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,0); // using 1 as a divisor
	SET_BIT(TIMSK,6); // enabling the overflow interrupt
	OCR2=0x00;
}
void TIM2_off(void)
{
	CLR_BIT(TCCR2,5); // the first two lines to switch to normal mode
	CLR_BIT(TCCR2,4);
	CLR_BIT(TIMSK,6); // disabling the overflow interrupt so the timer will be disabled
}


