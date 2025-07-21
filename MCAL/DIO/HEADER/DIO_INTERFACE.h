#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

void DIO_SelectDirectionForGroup(u8 groupName , u8 directionState);
void DIO_SelectDirectionForPin(u8 groupName , u8 pinName , u8 directionState);

void DIO_SelectOutputForGroup(u8 groupName , u8 state);
void DIO_SelectOutputForPin(u8 groupName , u8 pinName , u8 state);

u8 DIO_ReadInputValueForGroup(u8 groupName);
u8 DIO_ReadInputValueForPin(u8 groupName, u8 pinName);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
