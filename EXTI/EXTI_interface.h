/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_

void __vector_1(void)   __attribute__((signal,used));

void INT0_Enable(void);

void INT0_Disable(void);

void INT_CallBack(void (*CallBack)(void));

void EXTI_INT0_Intial(void);

void EXTI_INT0_SignalLatch(u8 Status);

void __vector_2(void)    __attribute__((signal,used));

void EXTI_INT1_Intial(void);

void EXTI_INT1_SignalLatch(u8 Status);

void __vector_3(void)    __attribute__((signal,used));

void EXTI_INT2_Intial(void);

void EXTI_INT2_SignalLatch(u8 Status);


#endif
