/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  TMR0_PRIVATE_H_
#define  TMR0_PRIVATE_H_

#define TCCR0         *((volatile u8*)0x53)
#define FOC0          7
#define WGM00         6
#define WGM01         3
#define COM00         4
#define COM01         5
#define CS00          0
#define CS01          1
#define CS02          2

#define TCNT0         *((volatile u8*)0x52)
#define OCR0          *((volatile u8*)0x5C)
#define TIMSK         *((volatile u8*)0x59)
#define TIFR          *((volatile u8*)0x58)

#define NORM         0
#define TOGG         1
#define CLR          2
#define SET          3

#define NORMAL        0
#define COMP_MTCH     1
#define PWM           2
#define WTCH_DOG      3

#endif
