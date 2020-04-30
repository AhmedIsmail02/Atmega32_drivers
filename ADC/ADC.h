/*
 * ADC.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed Magdy
 */

#ifndef ADC_H_
#define ADC_H_
typedef enum {
	ADC0=0x00,
	ADC1=0x01,
	ADC2=0x02,
	ADC3=0x03,
	ADC4=0x04,
	ADC5=0x05,
	ADC6=0x06,
	ADC7=0x07

}ADC_Channel_t;
extern void ADC_Init(void); 

extern void ADC_Start_Conversion(ADC_Channel_t ch);

extern u16 ADC_Getvalue(void);

#endif /* ADC_H_ */
