/*
 * main1.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Ahmed Magdy
 */
#include "stdtypes.h"
#include "DIO.h"
#include "KEYPAD_cfg.h"
#include "memmap.h"
#include "KEYPAD.h"

u8 KEYPAD_GetKey(void)
{
	u8 key='/';
	PORTC|=0x0F;
	for(u8 i=0;i<3;i++)
	{
		DDRC&=~(0x7F);
		DDRC|=(0X40>>i);
		for(u8 j=0;j<4;j++)
		{
			if(!(PINC&(0x08>>j)))
			{
				key=(j*3+i);
			}
		}

	}
	return key;
}
