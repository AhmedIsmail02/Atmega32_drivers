/*
 * KEYPAD.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed Magdy
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
typedef enum {
	KEY0='0',
	KEY1='1',
	KEY2='2',
	KEY3='3',
	KEY4='4',
	KEY5='5',
	KEY6='6',
	KEY7='7',
	KEY8='8',
	KEY9='9',
	KEYA='A',
	KEYB='B',
	KEYC='C',
	KEYD='D',
	KEYSTAR='*',
	KEYHASH='#',
	NOKEY
	}KEYPAD_t;







extern u8 KEYPAD_GetKey(void);
#endif /* KEYPAD_H_ */
