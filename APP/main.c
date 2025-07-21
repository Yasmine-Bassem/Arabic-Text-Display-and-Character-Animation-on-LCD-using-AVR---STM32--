#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/HEADER/DIO_PRIVATE.h"
#include "../MCAL/DIO/HEADER/DIO_INTERFACE.h"

#include "../HAL/LCD/HEADER/LCD_INTERFACE.h"
#include "../HAL/LCD/HEADER/LCD_PRIVATE.h"
#include "../HAL/LCD/HEADER/LCD_CONFIG.h"

#include <util/delay.h>

void main(){

	LCD_INIT();
	//Display My Name in Arabic
	u8 ya[8]={
		0b0010000,
		0b0010000,
		0b0010001,
		0b0010001,
		0b0011111,
		0,
		0b0001010,
		0
	};
	u8 s[8]={
		0,
		0,
		0b0010101,
		0b0010101,
		0b11111111,
		0,
		0,
		0
	};
	u8 da[8]={
		0,
		0,
		0,
		0,
		0b1111111,
		0,
		0,
		0
	};
	u8 m[8]={
		0,
		0,
		0,
		0,
		0b11111,
		0b10001,
		0b11111,
		0
	};
	u8 y[8]={
		0,
		0,
		0b0000001,
		0b0000001,
		0b1111111,
		0,
		0b0001010,
		0
		};
	u8 n[8]={
		0,
		0b00100,
		0b10001,
		0b10001,
		0b10001,
		0b10001,
		0b11111,
		0
		};

	u8 i = 0, line = LINE1;
	for( i ; i<11 ; i=i+2 ){

	LCD_CLEAR();
	LCD_CUSTUM_CHAR(ya,1,15-i,line);
	LCD_CUSTUM_CHAR(s,2,14-i,line);
	LCD_CUSTUM_CHAR(da,3,13-i,line);
	LCD_CUSTUM_CHAR(m,4,12-i,line);
	LCD_CUSTUM_CHAR(y,5,11-i,line);
	LCD_CUSTUM_CHAR(n,6,10-i,line);
	_delay_ms(500);
	if(line == LINE1){
		line = LINE2;
	}else if(line == LINE2){
		line = LINE1;
	}

	}
	LCD_CLEAR();

	//animation

	u8 person1_frame1[8] ={
		0b01110,
		0b10001,
		0b10001,
		0b00100,
		0b01110,
		0b10101,
		0b10101,
		0

	};
	u8 person1_frame2[8] ={
		0b01110,
		0b10001,
		0b10001,
		0b00100,
		0b01110,
		0b01110,
		0b01110,
		0

	};
	u8 person1_frame3[8] ={
		0b01110,
		0b10001,
		0b10001,
		0b00100,
		0b11111,
		0b00100,
		0b00100,
		0

	};
	u8 person2_frame1[8] ={
		0b00100,
		0b00100,
		0b00100,
		0b00100,
		0b01010,
		0b10001,
		0b10001,
		0b10001
	};
	u8 person2_frame2[8] ={
		0b00100,
		0b00100,
		0b00100,
		0b00100,
		0b01010,
		0b01010,
		0b01010,
		0b01010
	};

	u8 person2_frame3[8] ={
		0b00100,
		0b00100,
		0b00100,
		0b00100,
		0b01010,
		0b10010,
		0b00010,
		0b00010
	};
	u8 person2_frame4[8] ={
		0b00100,
		0b00100,
		0b00100,
		0b00100,
		0b01010,
		0b01001,
		0b01000,
		0b01000
	};
	u8 ball[8]={
			0,
			0,
			0,
			0,
			0b01110,
			0b10001,
			0b01110,

			0
	};

	LCD_DISPLAY_STRING("IT CAN RUN");
	_delay_ms(450);
	LCD_CLEAR();

	for (u8 pos = 0; pos < 16; pos++) {
		LCD_CLEAR();
		if (pos % 2 == 0) {
			LCD_CUSTUM_CHAR(person1_frame1, 0, pos, 0);
			LCD_CUSTUM_CHAR(person2_frame1, 1, pos, 1);
		} else {
			LCD_CUSTUM_CHAR(person1_frame2, 0, pos, 0);
			LCD_CUSTUM_CHAR(person2_frame2, 1, pos, 1);
		}
		_delay_ms(150);
	}

	LCD_CLEAR();
	LCD_DISPLAY_STRING("IT CAN PLAY ");
	LCD_GOTO_XY(LINE2,0);
	LCD_DISPLAY_STRING("FOOTBALL");
	_delay_ms(450);
	LCD_CLEAR();
	for (u8 pos = 0; pos < 16; pos++) {
		LCD_CLEAR();
		if (pos % 2 == 0) {
			LCD_CUSTUM_CHAR(person1_frame1, 0, pos, 0);
			LCD_CUSTUM_CHAR(person2_frame1, 1, pos, 1);
			LCD_CUSTUM_CHAR(ball, 2, pos+1, 1);

		} else {
			LCD_CUSTUM_CHAR(person1_frame2, 0, pos, 0);
			LCD_CUSTUM_CHAR(person2_frame2, 1, pos, 1);
			LCD_CUSTUM_CHAR(ball, 2, pos+1, 1);
		}
		_delay_ms(150);
	}

	LCD_CLEAR();
	LCD_DISPLAY_STRING("IT CAN DANCE");
	_delay_ms(450);
	LCD_CLEAR();
	while(1){
	LCD_CUSTUM_CHAR(person1_frame1, 0, 7, 0);
	LCD_CUSTUM_CHAR(person2_frame1, 1,7, 1);
	_delay_ms(150);
	LCD_CUSTUM_CHAR(person1_frame3, 0, 7, 0);
	LCD_CUSTUM_CHAR(person2_frame3, 1,7, 1);
	_delay_ms(150);
	LCD_CUSTUM_CHAR(person1_frame3, 0, 7, 0);
	LCD_CUSTUM_CHAR(person2_frame4, 1,7, 1);
	_delay_ms(150);
	}
}



