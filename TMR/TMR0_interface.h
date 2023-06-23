/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  TMR0_INTERFACE_H_
#define  TMR0_INTERFACE_H_

void TMR0_voidInit (void);

void TMR0_CallBackINT (void (*ptr)(void));

void TMR0_PWM (u8 Duty_Cycle);


#endif
