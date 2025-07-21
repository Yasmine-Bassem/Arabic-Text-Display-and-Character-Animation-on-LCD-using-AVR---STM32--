#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

#include "../HEADER/DIO_REGISTER.h"
#include "../HEADER/DIO_PRIVATE.h"
#include "../HEADER/DIO_INTERFACE.h"


void DIO_SelectDirectionForGroup(u8 groupName , u8 directionState){

		switch(groupName){
				case DIO_GROUPA:
					DIO_DDRA = directionState;
				break;
				case DIO_GROUPB:
					DIO_DDRB = directionState;
				break;
				case DIO_GROUPC:
					DIO_DDRC = directionState;
				break;
				case DIO_GROUPD:
					DIO_DDRD = directionState;
				break;
		}


}

void DIO_SelectDirectionForPin(u8 groupName , u8 pinName , u8 directionState){
	if(directionState == OUTPUT ){
			switch(groupName){
					case DIO_GROUPA:	SET_BIT(DIO_DDRA,pinName);	break;
					case DIO_GROUPB:	SET_BIT(DIO_DDRB,pinName);  break;
					case DIO_GROUPC:	SET_BIT(DIO_DDRC,pinName);	break;
					case DIO_GROUPD:	SET_BIT(DIO_DDRD,pinName);	break;
			}

	}else if(directionState == INPUT ){
			switch(groupName){
					case DIO_GROUPA:	CLEAR_BIT(DIO_DDRA,pinName);	break;
					case DIO_GROUPB:	CLEAR_BIT(DIO_DDRB,pinName);	break;
					case DIO_GROUPC:	CLEAR_BIT(DIO_DDRC,pinName);	break;
					case DIO_GROUPD:	CLEAR_BIT(DIO_DDRD,pinName);	break;
			}

		}

}
void DIO_SelectOutputForGroup(u8 groupName , u8 state){

	 switch(groupName){
	        case DIO_GROUPA:	DIO_PORTA = state;	break;
	        case DIO_GROUPB:	DIO_PORTB = state;	break;
	        case DIO_GROUPC:	DIO_PORTC = state;	break;
	        case DIO_GROUPD:	DIO_PORTD = state;	break;
	    }
}

void DIO_SelectOutputForPin(u8 groupName , u8 pinName , u8 state){

	if(state == HIGH ){
		switch(groupName){
				case DIO_GROUPA:	SET_BIT(DIO_PORTA,pinName);	break;
				case DIO_GROUPB:	SET_BIT(DIO_PORTB,pinName);	break;
				case DIO_GROUPC:	SET_BIT(DIO_PORTC,pinName);	break;
				case DIO_GROUPD:	SET_BIT(DIO_PORTD,pinName);	break;
		}

	}else if(state == LOW ){
		switch(groupName){
				case DIO_GROUPA:	CLEAR_BIT(DIO_PORTA,pinName);	break;
				case DIO_GROUPB:	CLEAR_BIT(DIO_PORTB,pinName);	break;
				case DIO_GROUPC:	CLEAR_BIT(DIO_PORTC,pinName);	break;
				case DIO_GROUPD:	CLEAR_BIT(DIO_PORTD,pinName);	break;
		}
	}
}

u8 DIO_ReadInputValueForGroup(u8 groupName){
	u8 groupState = 0;
	switch(groupName){
		case DIO_GROUPA:	groupState = DIO_PINA;	break;
		case DIO_GROUPB:	groupState = DIO_PINB;	break;
		case DIO_GROUPC:	groupState = DIO_PINC;	break;
		case DIO_GROUPD:	groupState = DIO_PIND;	break;
	}
	return groupState;

}
u8 DIO_ReadInputValueForPin(u8 groupName, u8 pinName){
	u8 pinState = 0;
	switch(groupName){
		case DIO_GROUPA:	pinState = GET_BIT(DIO_PINA,pinName);	break;
		case DIO_GROUPB:	pinState = GET_BIT(DIO_PINB,pinName);	break;
		case DIO_GROUPC:	pinState = GET_BIT(DIO_PINC,pinName);	break;
		case DIO_GROUPD:	pinState = GET_BIT(DIO_PIND,pinName);	break;
	}
	return pinState;

}
