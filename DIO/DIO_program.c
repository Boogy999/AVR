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

/********************************************************************************/
u8 DIO_u8SETPinDirection(u8 COPY_u8Port,u8 COPY_u8Pin,u8 COPY_u8Direction)
{
	u8 Local_u8ErrorState=0;
	if (COPY_u8Pin <= DIO_u8PIN7)
	{
		if (COPY_u8Direction == DIO_u8PIN_INPUT)
		{
			switch (COPY_u8Port)
			{
			case DIO_u8PORTA : CLR_bit(DDRA,COPY_u8Pin); break;
			case DIO_u8PORTB : CLR_bit(DDRB,COPY_u8Pin); break;
			case DIO_u8PORTC : CLR_bit(DDRC,COPY_u8Pin); break;
			case DIO_u8PORTD : CLR_bit(DDRD,COPY_u8Pin); break;
			default: Local_u8ErrorState = 1;   break;
			}
		}else if (COPY_u8Direction == DIO_u8PIN_OUTPUT)
		{
			switch (COPY_u8Port)
			{
			case DIO_u8PORTA : SET_bit(DDRA,COPY_u8Pin); break;
			case DIO_u8PORTB : SET_bit(DDRB,COPY_u8Pin); break;
			case DIO_u8PORTC : SET_bit(DDRC,COPY_u8Pin); break;
			case DIO_u8PORTD : SET_bit(DDRD,COPY_u8Pin); break;
			default: Local_u8ErrorState = 1;   break;
			}

		}else
		{
			Local_u8ErrorState = 1;
		}
	}else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
/**************************************************************************/
u8 DIO_u8SETPortDirection(u8 COPY_u8Port,u8 COPY_u8Direction)
{
	u8 Local_u8ErrorState=0;
	switch (COPY_u8Port)
	{
	case DIO_u8PORTA: DDRA = COPY_u8Direction; break;
	case DIO_u8PORTB: DDRB = COPY_u8Direction; break;
	case DIO_u8PORTC: DDRC = COPY_u8Direction; break;
	case DIO_u8PORTD: DDRD = COPY_u8Direction; break;
	default: Local_u8ErrorState = 1; break;
	}

	return Local_u8ErrorState ;
}
/****************************************************************************/
u8 DIO_u8SETPinValue(u8 COPY_u8Port,u8 COPY_u8Pin,u8 COPY_u8Value)
{
	u8 Local_u8ErrorState=0;
	if (COPY_u8Pin <= DIO_u8PIN7)
	{
		if (COPY_u8Value == DIO_u8PIN_HIGH)
		{
			switch (COPY_u8Port)
			{
			case DIO_u8PORTA : SET_bit(PORTA,COPY_u8Pin); break;
			case DIO_u8PORTB : SET_bit(PORTB,COPY_u8Pin); break;
			case DIO_u8PORTC : SET_bit(PORTC,COPY_u8Pin); break;
			case DIO_u8PORTD : SET_bit(PORTD,COPY_u8Pin); break;
			default: Local_u8ErrorState = 1; break;
			}
		}else if (COPY_u8Value == DIO_u8PIN_LOW)
		{
			switch (COPY_u8Port)
			{
			case DIO_u8PORTA : CLR_bit(PORTA,COPY_u8Pin); break;
			case DIO_u8PORTB : CLR_bit(PORTB,COPY_u8Pin); break;
			case DIO_u8PORTC : CLR_bit(PORTC,COPY_u8Pin); break;
			case DIO_u8PORTD : CLR_bit(PORTD,COPY_u8Pin); break;
			default: Local_u8ErrorState = 1; break;
			}
		}
	}else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState ;
}
/****************************************************************************/
u8 DIO_u8SETPortValue(u8 COPY_u8Port,u8 COPY_u8Value)
{
	u8 Local_u8ErrorState=0;
	switch (COPY_u8Port)
	{
	case DIO_u8PORTA : PORTA = COPY_u8Value; break;
	case DIO_u8PORTB : PORTB = COPY_u8Value; break;
	case DIO_u8PORTC : PORTC = COPY_u8Value; break;
	case DIO_u8PORTD : PORTD = COPY_u8Value; break;
	default: Local_u8ErrorState = 1; break;
	}

	return Local_u8ErrorState ;
}
/****************************************************************************/
u8 DIO_u8GetPinValue(u8 COPY_u8Port,u8 COPY_u8Pin, u8* COPY_pu8Value)
{
	u8 Local_u8ErrorState=0;
	if ((COPY_u8Pin <= DIO_u8PIN7) && (COPY_pu8Value != NULL))
	{
		switch (COPY_u8Port)
		{
		case DIO_u8PORTA : *COPY_pu8Value = GET_bit(PINA,COPY_u8Pin); break;
		case DIO_u8PORTB : *COPY_pu8Value = GET_bit(PINB,COPY_u8Pin); break;
		case DIO_u8PORTC : *COPY_pu8Value = GET_bit(PINC,COPY_u8Pin); break;
		case DIO_u8PORTD : *COPY_pu8Value = GET_bit(PIND,COPY_u8Pin); break;
		default: Local_u8ErrorState = 1; break;
		}

	}else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState ;

}
