/*
 * LCD_CONFIG.h
 *
 *  Created on: Jul 20, 2025
 *      Author: Right Click
 */

#ifndef HAL_LCD_HEADER_LCD_CONFIG_H_
#define HAL_LCD_HEADER_LCD_CONFIG_H_

#define LCD_DATA    DIO_GROUPA
#define LCD_CONTROL DIO_GROUPB

#define LCD_RS DIO_PIN0
#define LCD_RW DIO_PIN1
#define LCD_E  DIO_PIN2

/** 	COMMANDS	**/

#define LCD_CLEAR_DISPLAY 		 	0x01
#define LCD_DISPLAY_OFF  		 	0x08
#define LCD_DISPLAY_ON   			0x0C
#define LCD_DISPLAY_CURSOR_ON    	0x0E
#define LCD_DISPLAY_BLINK_ON     	0x15
#define LCD_ENTRY_MODE			 	0x06
#define LCD_8BIT_MODE_2LINE_5X8     0x38

#define LINE1 0
#define LINE2 1

#define LINE1ADDRESS 0x00
#define LINE2ADDRESS 0x40

#define SETDDRAMADDRESS 0X80
#define SETCGRAMADDRESS 0x40


#endif /* HAL_LCD_HEADER_LCD_CONFIG_H_ */
