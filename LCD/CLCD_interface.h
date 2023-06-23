/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  HAL        ***********************************/
/********************     SWC :    CLCD       ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef      _CLCD_INTERFACE_H_
#define      _CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 COPY_u8Command);

void CLCD_voidSendData(u8 COPY_u8Data);

void CLCD_voidWrite4BIT(u8 COPY_u8Data);

void CLCD_voidWriteSpecialCharacter(u8 * SpecialChar,u8 PatternNumber);

void CLCD_voidInit8BIT(void);

void CLCD_voidInit4BIT(void);

void CLCD_voidSendString(const char* COPY_pcString);

void CLCD_voidGoToXY(u8 COPY_u8XPos,u8 COPY_u8YPos);

void CLCD_voidWriteSpecialChar(u8* COPY_u8Arr,u8 COPY_u8BlockNo,u8 COPY_u8Posx,u8 COPY_u8Posy);

void CLCD_voidWriteNumber(u32 COPY_u32Number,u8 COPY_u8XPos,u8 COPY_u8YPos);

void CLCD_voidSecondLine(void);

u8 CLCD_u8Opertation(u8 OP1,u8 OP2,u8 OPeration);
#endif
