/*
 * LCD_PROGRAM.c
 *
 *  Created on: Jul 20, 2025
 *      Author: Right Click
 */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

#include "../../../MCAL/DIO/HEADER/DIO_PRIVATE.h"
#include "../../../MCAL/DIO/HEADER/DIO_INTERFACE.h"

#include "../HEADER/LCD_CONFIG.h"
#include "../HEADER/LCD_INTERFACE.h"
#include <util/delay.h>


void LCD_INIT(){

	DIO_SelectDirectionForGroup( LCD_DATA , ALLOUTPUT );
	DIO_SelectDirectionForPin( LCD_CONTROL , LCD_RS , OUTPUT );
	DIO_SelectDirectionForPin( LCD_CONTROL , LCD_RW , OUTPUT );
	DIO_SelectDirectionForPin( LCD_CONTROL , LCD_E , OUTPUT );

	_delay_ms(40);
	LCD_SEND_COMMAND(LCD_8BIT_MODE_2LINE_5X8);
	_delay_us(40);
	LCD_SEND_COMMAND(LCD_DISPLAY_ON);
	_delay_us(40);
	LCD_SEND_COMMAND(LCD_CLEAR_DISPLAY);
	_delay_ms(2);
	LCD_SEND_COMMAND(LCD_ENTRY_MODE);

}
void LCD_SEND_COMMAND(u8 command){
	//rest rs
	DIO_SelectOutputForPin( LCD_CONTROL , LCD_RS,LOW);
	//RW
	DIO_SelectOutputForPin( LCD_CONTROL , LCD_RW,LOW);
	//DATA
	DIO_SelectOutputForGroup( LCD_DATA , command);

	DIO_SelectOutputForPin( LCD_CONTROL , LCD_E , HIGH );
	_delay_ms(2);
	DIO_SelectOutputForPin(LCD_CONTROL , LCD_E,LOW);







}
void LCD_SEND_DATA(u8 data){
	//rest rs
	DIO_SelectOutputForPin( LCD_CONTROL , LCD_RS,HIGH);
	//RW
	DIO_SelectOutputForPin( LCD_CONTROL , LCD_RW , LOW );
	//DATA
	DIO_SelectOutputForGroup( LCD_DATA , data );

	DIO_SelectOutputForPin( LCD_CONTROL, LCD_E , HIGH );
	_delay_ms(2);
	DIO_SelectOutputForPin( LCD_CONTROL , LCD_E , LOW );




}
void LCD_CLEAR(){

	LCD_SEND_COMMAND(LCD_CLEAR_DISPLAY);
		_delay_ms(2);

}
void LCD_DISPLAY_STRING(u8* string){

	u8 i=0;
	while(string[i] != '\0'){
		LCD_SEND_DATA(string[i]);
		i++;
	}

}
void LCD_GOTO_XY(u8 ypos ,u8 xpos){
	u8 DDRAM_address = 0 ;
	switch(ypos){
		case LINE1: DDRAM_address =LINE1ADDRESS + xpos; break;
		case LINE2: DDRAM_address =LINE2ADDRESS + xpos; break;

	}
	LCD_SEND_COMMAND(DDRAM_address + SETDDRAMADDRESS);

}

void LCD_CUSTUM_CHAR(u8* arr , u8 blockno , u8 xpos , u8 ypos){
	if(blockno < 8){
		u8 CGRAM_address =0;
		CGRAM_address = blockno * 8 ;
		LCD_SEND_COMMAND(CGRAM_address + SETCGRAMADDRESS);
		for(u8 i = 0 ; i<8 ; i++){
			LCD_SEND_DATA(arr[i]);
		}
		LCD_GOTO_XY( ypos ,xpos);
		LCD_SEND_DATA(blockno);

	}


}
void LCD_DISPLAY_NUMBER(u32 num){
    u8 str[10];
    u8 i = 0;

    if (num == 0) {
        LCD_SEND_DATA('0');
        return;
    }

    while (num > 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i++;
    }

    while (i > 0) {
        i--;
        LCD_SEND_DATA(str[i]);
    }
}

