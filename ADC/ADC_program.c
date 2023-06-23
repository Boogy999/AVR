/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"

static void (*ADC_CallBack) (void);

void ADC_voidInit (void)
{
	/*Activate VCC as V reference*/
	SET_bit(ADMUX,ADMUX_REFS0);
	CLR_bit(ADMUX,ADMUX_REFS1);

	/*Activate left Adjustment*/
	SET_bit(ADMUX,ADMUX_ADLAR);

	/*Activate PreScaler*/
	SET_bit(ADCSRA,ADCSRA_ADPS0);
	SET_bit(ADCSRA,ADCSRA_ADPS1);
	SET_bit(ADCSRA,ADCSRA_ADPS2);

	/*Enable the ADC*/
	SET_bit(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartReadingPoll(u8 ChannelNum)
{
   /*Active Channel*/
   ADMUX |= ChannelNum;

   /*Start Conversion*/
   SET_bit(ADCSRA,ADCSRA_ADSC);

   /*Polling on ADIF to Set Flag*/
   while (GET_bit(ADCSRA,ADCSRA_ADIF) == 0)
   {
	   SET_bit(ADCSRA,ADCSRA_ADIF);
   }

   return ADCH;
}

u8 ADC_u8StartReadingINT(u8 ChannelNum)
{

   /*Active Channel*/
   ADMUX |= ChannelNum;

   /*Enable GIE*/
    SET_bit(SREG,7);

   /*Set the ADC Interrupt*/
   SET_bit(ADCSRA,ADCSRA_ADIE);

   /*Start Conversion*/
   SET_bit(ADCSRA,ADCSRA_ADSC);

   return ADCH;
}

void	ADC_voidSetCallBack(void (*pf)(void))
{
	if (pf != NULL)
	{
		ADC_CallBack = pf;
	}
}

void __vector_16 (void)   __attribute__((signal,used));
void __vector_16 (void)
{
	ADC_CallBack();
}
