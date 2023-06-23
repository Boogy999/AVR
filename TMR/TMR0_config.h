/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  TMR0_CONFIG_H_
#define  TMR0_CONFIG_H_

/*to set the mode of timer0
 * select 1- NORMAL for normal mode
 *        2- COMP_MTCH for compare match mode
 *        3- PWM for PWM mode
 *        4- FAST_PWM for watch dog mode  */

#define TIMER_MODE  PWM

/*the action of CTC with PWM
 * select 1- NORM for normal mode, Disconnect oc0
 *        2- RES for Reserved OC0
 *        3- CLR to clear OC0
 *        4- SET to set OC0   */
#define CTC_ACT  CLR



#endif
