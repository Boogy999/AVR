/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void(*Call)(void);



void EXTI_INT0_Intial(void)
{
   #if EXTI_SENSE == LOW_LEVEL

	CLR_bit(MCUCR,MCUCR_ISC00);
	CLR_bit(MCUCR,MCUCR_ISC01);

  #elif EXTI_SENSE == ON_CHANGE
	SET_bit(MCUCR,MCUCR_ISC00);
	CLR_bit(MCUCR,MCUCR_ISC01);
  #elif EXTI_SENSE == FALL_EDGE
	CLR_bit(MCUCR,MCUCR_ISC00);
	SET_bit(MCUCR,MCUCR_ISC01);
  #elif EXTI_SENSE == RAIS_EDGE
	SET_bit(MCUCR,MCUCR_ISC00);
	SET_bit(MCUCR,MCUCR_ISC01);
#endif
	/*Reset the Flag*/
   SET_bit(GIFR,INT0);

   CLR_bit(GICR,INT0);
   /*Enable general Interrupt*/
   SET_bit(SREG,7);
}

void INT0_Enable(void)
{
	SET_bit(GICR,INT0);
}

void INT0_Disable(void)
{
	CLR_bit(GICR,INT0);
}

void INT_CallBack(void (*CallBack)(void))
{
	if (CallBack != NULL)
	{
	   Call = CallBack;
	}
}
void __vector_1(void)	__attribute__((signal,used));
void __vector_1(void)
{
	Call();
}


