/*
 * ADC_memmap.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed Magdy
 */

#ifndef ADC_MEMMAP_H_
#define ADC_MEMMAP_H_
#define ADMUX (*((volatile u8*)0x27))
#define ADCSRA (*((volatile u8*)0x26))
#define ADCH (*((volatile u8*)0x25))
#define ADCL (*((volatile u8*)0x24))
#define SFIOR (*((volatile u8*)0x50))
#define ADSC 6
#define ADIF 4
#endif /* ADC_MEMMAP_H_ */
