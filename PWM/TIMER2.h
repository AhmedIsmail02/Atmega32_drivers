/*
 * TIMER0.h
 *
 *  Created on: Oct 3, 2019
 *      Author: Ahmed Magdy
 */

#ifndef TIMER0_TIMER1_H_
#define TIMER0_TIMER1_H_
extern void TIM2_init(void);
#define ICR1 (ICR1L | (ICR1H<<8))
void TIM2_off(void);
#endif /* TIMER0_TIMER1_H_ */
