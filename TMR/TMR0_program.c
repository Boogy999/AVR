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

#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"
#include "EXTI_private.h"
#include "ADC_interface.h"

static void (*Call)(void);

void TMR0_voidInit (void)
{
#if   TIMER_MODE == NORMAL

	CLR_bit(TCCR0,WGM00);
	CLR_bit(TCCR0,WGM01);

#elif TIMER_MODE == COMP_MTCH

	CLR_bit(TCCR0,WGM00);
	SET_bit(TCCR0,WGM01);

#elif TIMER_MODE == PWM

	SET_bit(TCCR0,WGM00);
	CLR_bit(TCCR0,WGM01);

#elif TIMER_MODE == FAST_PWM
	SET_bit(TCCR0,WGM00);
	SET_bit(TCCR0,WGM01);
#endif
	/*************************/

#if   CTC_ACT == NORM

	CLR_bit(TCCR0,COM00);
	CLR_bit(TCCR0,COM01);

#elif CTC_ACT == TOGG

	SET_bit(TCCR0,COM00);
	CLR_bit(TCCR0,COM01);

#elif CTC_ACT == CLR

	CLR_bit(TCCR0,COM00);
	SET_bit(TCCR0,COM01);

#elif CTC_ACT == SET
	SET_bit(TCCR0,WGM00);
	SET_bit(TCCR0,WGM01);
#endif

    /*setting the PreScaler value*/
	SET_bit(TCCR0,CS00);
	CLR_bit(TCCR0,CS01);
	SET_bit(TCCR0,CS02);

	/*Enable timer interrupt*/
	//SET_bit(TIMSK,0);
	/*Enable general Interrupt*/
	//SET_bit(SREG,7);
	//TCNT0 = 0;

}

void TMR0_PWM (u8 Duty_Cycle)
{
	u8 Result = Duty_Cycle;
	Result =map(Duty_Cycle,0,99,0,255);
	OCR0 = Result;
}

void TMR0_CallBackINT (void (*ptr)(void))
{
	if (ptr != NULL)
	{
		Call = ptr;
	}
}
void __vector_11 (void)     __attribute__((signal,used));
void __vector_11 (void)
{
  Call();
}
