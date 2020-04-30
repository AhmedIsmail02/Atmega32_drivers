/*
 * LCD.h
 *
 *  Created on: Sep 6, 2019
 *      Author: Ahmed Magdy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
typedef enum {
	OKAY=0,
	NOKAY
}LCD_Status;
#define CMND_FUNC_SET_CMND 0x38
#define CMND_DISPLAY_ON_CURSOR_OFF 0x0C
#define CMND_DISPLAY_CLR 0x01
#define CMND_ENTRY_MODE_SET 0x06
#define LCD_CONTROL_PORT PB
#define LCD_DATA_PORT PD
#define LCD_RS_PIN PIN0
#define LCD_RW_PIN PIN1
#define LCD_E_PIN PIN2
#define LINE1_BASE 0x80
#define LINE2_BASE 0xC0
#define SHIFT_RIGHT 0x1B
#define CGRAM 0x40
void LCD_init(void);
LCD_Status LCD_send_cmnd(u8 cmnd);

LCD_Status LCD_send_char(u8 data);
LCD_Status LCD_GO_TO_X_Y(u8 line,u8 y);
LCD_Status LCD_send_pattern(u8 line , u8 y);
LCD_Status LCD_send_string(u8 *ptr);
#endif /* LCD_INT_H_ */
