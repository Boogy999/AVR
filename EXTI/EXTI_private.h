/********************************************************************************/
/********************************************************************************/
/********************     Author : Youssef    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  EXTI_PRIVATE_H_
#define  EXTI_PRIVATE_H_

#define EXT_INT0          2
#define EXT_INT1          3
#define EXT_INT2          4

#define MCUCR         *((volatile u8*)0x55)
#define MCUCR_ISC00    0
#define MCUCR_ISC01    1
#define MCUCR_ISC10    2
#define MCUCR_ISC11    3

#define MCUCSR        *((volatile u8*)0x54)
#define MCUCSR_ISC2    6

#define GIFR          *((volatile u8*)0x5A)
#define GICR          *((volatile u8*)0x5B)
#define SREG          *((volatile u8*)0x5F)

#define INT1           7
#define INT0           6
#define INT2           5

#define LOW_LEVEL      1
#define ON_CHANGE      2
#define FALL_EDGE      3
#define RAIS_EDGE      4


#endif
