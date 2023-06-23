/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include "SSD_interface.h"

/********************************************************************************/
u8 SSD_u8SetNumber(u8 COPY_u8Number,SSD_Type* COPY_SSD)
{
	u8 Local_Errorstate = 0;
		if (COPY_SSD->SSD_u8CommonType == SSD_u8CommonAnode)
		{
			DIO_u8SETPinDirection(COPY_SSD->SSD_u8EnablePort,COPY_SSD->SSD_u8EnablePin,DIO_u8PIN_OUTPUT);
			DIO_u8SETPinValue(COPY_SSD->SSD_u8EnablePort,COPY_SSD->SSD_u8EnablePin,DIO_u8PIN_HIGH);
			DIO_u8SETPortDirection(COPY_SSD->SSD_u8Port,DIO_u8PORT_OUTPUT);
			DIO_u8SETPortValue(COPY_SSD->SSD_u8Port,~COPY_u8Number);


		}else if (COPY_SSD->SSD_u8CommonType == SSD_u8CommonCathod)
		{
			DIO_u8SETPinDirection(COPY_SSD->SSD_u8EnablePort,COPY_SSD->SSD_u8EnablePin,DIO_u8PIN_OUTPUT);
			DIO_u8SETPinValue(COPY_SSD->SSD_u8EnablePort,COPY_SSD->SSD_u8EnablePin,DIO_u8PIN_LOW);
			//DIO_u8SETPortDirection(COPY_SSD->SSD_u8Port,DIO_u8PORT_OUTPUT);
			//DIO_u8SETPortValue(COPY_SSD->SSD_u8Port,COPY_u8Number);
			DIO_u8SETPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
		    DIO_u8SETPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
		    DIO_u8SETPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_OUTPUT);
			DIO_u8SETPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

		    DIO_u8SETPortValue(DIO_u8PORTB,COPY_u8Number);

		}else{
			Local_Errorstate = 1;
		}
	return Local_Errorstate;
}

