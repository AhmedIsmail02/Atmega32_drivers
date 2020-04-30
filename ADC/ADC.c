/*
 * ADC.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Ahmed Magdy
 */

#include "stdtypes.h"
#include "ADC_memmap.h"
#include "Util.h"
#include "ADC.h"
void ADC_Init(void)
{

	ADMUX = 0b01000000; //using AVCC with AREF with external cap , using channel ADC0
	ADCSRA = 0b10001110; //Enabling ADC , Enabling ADC Interrupt , setting pre-scaler to 64
}
void ADC_Start_Conversion(ADC_Channel_t ch)
{
	MOD_REG(ADMUX,ch);
	SET_BIT(ADCSRA,ADSC); // starting conversion 

}
u16 ADC_Getvalue(void)
{
	u16 adcresult = ADCL | (ADCH <<8); // returning the result
	return adcresult;
}


