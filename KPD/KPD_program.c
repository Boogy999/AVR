/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  HAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_voidIntial(void)
{
	DIO_u8SETPinDirection(ROW_PORT,ROW1_PIN,DIO_u8PIN_INPUT);
	DIO_u8SETPinDirection(ROW_PORT,ROW2_PIN,DIO_u8PIN_INPUT);
	DIO_u8SETPinDirection(ROW_PORT,ROW3_PIN,DIO_u8PIN_INPUT);
	DIO_u8SETPinDirection(ROW_PORT,ROW4_PIN,DIO_u8PIN_INPUT);

	DIO_u8SETPinValue(ROW_PORT,ROW1_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(ROW_PORT,ROW2_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(ROW_PORT,ROW3_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(ROW_PORT,ROW4_PIN,DIO_u8PIN_HIGH);

	DIO_u8SETPinDirection(COL_PORT,COL1_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(COL_PORT,COL2_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(COL_PORT,COL3_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SETPinDirection(COL_PORT,COL4_PIN,DIO_u8PIN_OUTPUT);

	DIO_u8SETPinValue(COL_PORT,COL1_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(COL_PORT,COL2_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(COL_PORT,COL3_PIN,DIO_u8PIN_HIGH);
	DIO_u8SETPinValue(COL_PORT,COL4_PIN,DIO_u8PIN_HIGH);

}

u8 KPD_u8KeyPad(void)
{
	u8 Local_PressedKey = NO_PressedKey;
	u8 ROW_Index;
	u8 COL_Index;
	u8 LocalPressState;
	u8 KPD_Arr[4][4] = {{7,8,9,'/'}
	                   ,{4,5,6,'*'}
	                   ,{1,2,3,'-'}
                       ,{'C',0,'=','+'}};

	u8 COL_Arr[4] = {COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN};

	u8 ROW_Arr[4] = {ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN};
while (1)
{
	for(COL_Index=0;COL_Index<4;COL_Index++)
	{
		DIO_u8SETPinValue(COL_PORT,COL_Arr[COL_Index],DIO_u8PIN_LOW);

		for(ROW_Index=0;ROW_Index<4;ROW_Index++)
		{
			DIO_u8GetPinValue(ROW_PORT,ROW_Arr[ROW_Index],&LocalPressState);
			if ( LocalPressState == DIO_u8PIN_LOW )
			{
				Local_PressedKey = KPD_Arr[ROW_Index][COL_Index];
				while ( LocalPressState == DIO_u8PIN_LOW )
				{
					DIO_u8GetPinValue(ROW_PORT,ROW_Arr[ROW_Index],&LocalPressState);
				}
				return Local_PressedKey;
			}
		}

		DIO_u8SETPinValue(COL_PORT,COL_Arr[COL_Index],DIO_u8PIN_HIGH);
	}

	return Local_PressedKey;
}
}



