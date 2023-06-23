/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  HAL        ***********************************/
/********************     SWC :    CLCD       ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 COPY_u8Command)
{
	/* set RS 0 to active command*/
	DIO_u8SETPinValue(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/* set E enable Pin*/
	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	/* set register to send command*/

	CLCD_voidWrite4BIT(COPY_u8Command);
}


void CLCD_voidSendData(u8 COPY_u8Data)
{
	/* set RS 1 to active command*/
	//DIO_u8SETPinDirection(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinValue(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	//DIO_u8SETPinDirection(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	/* set 4 bit data*/

	CLCD_voidWrite4BIT(COPY_u8Data);


}

void CLCD_voidWrite4BIT(u8 COPY_u8Data)
{

	DIO_u8SETPinValue(CLCD_D4_PORT,CLCD_D4_PIN,GET_bit(COPY_u8Data,4));
	DIO_u8SETPinValue(CLCD_D5_PORT,CLCD_D5_PIN,GET_bit(COPY_u8Data,5));
	DIO_u8SETPinValue(CLCD_D6_PORT,CLCD_D6_PIN,GET_bit(COPY_u8Data,6));
	DIO_u8SETPinValue(CLCD_D7_PORT,CLCD_D7_PIN,GET_bit(COPY_u8Data,7));

	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	DIO_u8SETPinValue(CLCD_D4_PORT,CLCD_D4_PIN,GET_bit(COPY_u8Data,0));
	DIO_u8SETPinValue(CLCD_D5_PORT,CLCD_D5_PIN,GET_bit(COPY_u8Data,1));
	DIO_u8SETPinValue(CLCD_D6_PORT,CLCD_D6_PIN,GET_bit(COPY_u8Data,2));
	DIO_u8SETPinValue(CLCD_D7_PORT,CLCD_D7_PIN,GET_bit(COPY_u8Data,3));

	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SETPinValue(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}


void CLCD_voidInit4BIT(void)
{
	DIO_u8SETPinDirection(CLCD_D4_PORT,CLCD_D4_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(CLCD_D5_PORT,CLCD_D5_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(CLCD_D6_PORT,CLCD_D6_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(CLCD_D7_PORT,CLCD_D7_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(CLCD_E_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	/*wait for 40 ms after start */
	_delay_ms(40);
	CLCD_voidSendCommand(0x33);
	_delay_ms(10);
	CLCD_voidSendCommand(0x32);
	_delay_ms(10);
	CLCD_voidSendCommand(0x28);
	CLCD_voidSendCommand(0x0c);
	CLCD_voidSendCommand(0x06);
	//_delay_ms(10);

	//_delay_ms(10);
	//CLCD_voidSendCommand(0b10000000);


}

void CLCD_voidSendString(const char* COPY_pcString)
{

	u8 i = 0;

	while (COPY_pcString[i] != '\0')
	{
		CLCD_voidSendData(COPY_pcString[i]);
		i++;
	}
}

void CLCD_voidGoToXY(u8 COPY_u8XPos,u8 COPY_u8YPos)
{
	u8 Local_u8Address =0;
	if (COPY_u8XPos<4)
	{
		switch (COPY_u8XPos)
		{
		case 0:Local_u8Address = COPY_u8YPos;break;
		case 1:Local_u8Address = COPY_u8YPos + 0x40;break;
		case 2:Local_u8Address = COPY_u8YPos + 0x14;break;
		case 3:Local_u8Address = COPY_u8YPos + 0x54;break;
		}
	}
	CLCD_voidSendCommand(Local_u8Address + 128);
}
/*************************************************************************/

void CLCD_voidWriteSpecialChar(u8* COPY_u8Arr,u8 COPY_u8BlockNo,u8 COPY_u8Posx,u8 COPY_u8Posy)
{
	u8 Local_u8CGRAMAddress = COPY_u8BlockNo*8;
	CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);
	for (u8 i=0;i<9;i++)
	{
		CLCD_voidSendData(COPY_u8Arr[i]);
	}
	CLCD_voidGoToXY(COPY_u8Posx,COPY_u8Posy);
	CLCD_voidSendData(COPY_u8BlockNo);
}

void CLCD_voidWriteNumber(u32 COPY_u32Number,u8 COPY_u8XPos,u8 COPY_u8YPos)
{
	u8 Local_u8digit = 0;
	u8 Local_u8NumOfDigits =0;
	u32 copy = COPY_u32Number;
	while (copy != 0)
	{
		copy = copy/10;
		Local_u8NumOfDigits++;
	}
	Local_u8NumOfDigits--;
	while (COPY_u32Number != 0)
	{
		Local_u8digit = COPY_u32Number %10;
		COPY_u32Number = COPY_u32Number /10;

		switch (Local_u8digit)
		{
		case 0 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('0');
			Local_u8NumOfDigits--;
			break;
		case 1 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('1');
			Local_u8NumOfDigits--;
			break;
		case 2 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('2');
			Local_u8NumOfDigits--;
			break;
		case 3 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('3');
			Local_u8NumOfDigits--;
			break;
		case 4 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('4');
			Local_u8NumOfDigits--;
			break;
		case 5 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('5');
			Local_u8NumOfDigits--;
			break;

		case 6 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('6');
			Local_u8NumOfDigits--;
			break;

		case 7 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('7');
			Local_u8NumOfDigits--;
			break;

		case 8 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('8');
			Local_u8NumOfDigits--;
			break;
		case 9 :
			CLCD_voidGoToXY(COPY_u8XPos,Local_u8NumOfDigits + COPY_u8YPos);
			CLCD_voidSendData('9');
			Local_u8NumOfDigits--;
			break;
		}
	}
}

/*void CLCD_voidSecondLine(void)
{
	 CLCD_voidSendCommand(0x16+0b11000000);
	 u8 Local_u8FirstAddress = *((u8*)0x16);
	 //u8 Local_u8Address = 0x40;
	if (Local_u8FirstAddress != 0)
	{
		CLCD_voidSendCommand(0x40+128);
	}
}
 */
void CLCD_voidWriteSpecialCharacter(u8 * SpecialChar,u8 PatternNumber)
{
	u8 LocalAddress = 0,LocalItrator;
	LocalAddress = PatternNumber*8;

	CLCD_voidSendCommand(LocalAddress + 64);
	for (LocalItrator=0;LocalItrator<8;LocalItrator++)
	{
		CLCD_voidSendData(SpecialChar[LocalItrator]);
	}
	CLCD_voidSendData(PatternNumber);
}

u8 CLCD_u8Opertation(u8 OP1,u8 OP2,u8 Operation)
{
	u8 OP_Result = 0;
	switch(Operation)
	{
	case '+':OP_Result = OP1 + OP2;break;
	case '-':OP_Result = OP1 - OP2;break;
	case '*':OP_Result = OP1 * OP2;break;
	case '/':OP_Result = OP1 / OP2;break;
	default: CLCD_voidSendData('E');
	}
	return OP_Result;
}
