/*
 * LCD_INTERFACE.h
 *
 *  Created on: Jul 20, 2025
 *      Author: Right Click
 */

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_

void LCD_INIT();
void LCD_SEND_COMMAND(u8 command);
void LCD_SEND_DATA(u8 data);
void LCD_CLEAR();
void LCD_DISPLAY_STRING(u8* string);
void LCD_GOTO_XY(u8 xpos ,u8 ypos);
void LCD_CUSTUM_CHAR(u8* arr , u8 blockno , u8 xpos , u8 ypos);
void LCD_DISPLAY_NUMBER(u32 num);
#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
