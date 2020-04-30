/*
 * TIMER0_memmap.h
 *
 *  Created on: Oct 3, 2019
 *      Author: Ahmed Magdy
 */

#ifndef TIMER0_TIMER1_MEMMAP_H_
#define TIMER0_TIMER1_MEMMAP_H_
#define TCCR0 (*((volatile u8*)0x53))
#define TCNT0 (*((volatile u8*)0x52))
#define OCR0 (*((volatile u8*)0x5C))
#define TIMSK (*((volatile u8*)0x59))
#define SREG (*((volatile u8*)0x5F))
#define TCCR1A (*((volatile u8*)0x4F))
#define TCCR1B (*((volatile u8*)0x4E))
#define TCNT1H (*((volatile u8*)0x4D))
#define TCNT1L (*((volatile u8*)0x4C))
#define OCR1AH (*((volatile u8*)0x4B))
#define OCR1AL (*((volatile u8*)0x4A))
#define OCR1BH (*((volatile u8*)0x49))
#define OCR1BL (*((volatile u8*)0x48))
#define ICR1H (*((volatile u8*)0x47))
#define ICR1L (*((volatile u8*)0x46))
#define TCCR2 (*((volatile u8*)0x45))
#define TCNT2 (*((volatile u8*)0x45))
#define OCR2 (*((volatile u8*)0x43))


#endif /* TIMER0_TIMER1_MEMMAP_H_ */
