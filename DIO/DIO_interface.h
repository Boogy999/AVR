/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  MCAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/


#ifndef  DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_

#define DIO_u8PIN_OUTPUT     1
#define DIO_u8PIN_INPUT      0

#define DIO_u8PIN_HIGH       1
#define DIO_u8PIN_LOW        0

#define DIO_u8PORT_OUTPUT    0xff
#define DIO_u8PORT_INPUT     0

#define DIO_u8PORT_HIGH      0xff
#define DIO_u8PORT_LOW       0

#define DIO_u8PORTA          0
#define DIO_u8PORTB          1
#define DIO_u8PORTC          2
#define DIO_u8PORTD          3

#define DIO_u8PIN0           0
#define DIO_u8PIN1           1
#define DIO_u8PIN2           2
#define DIO_u8PIN3           3
#define DIO_u8PIN4           4
#define DIO_u8PIN5           5
#define DIO_u8PIN6           6
#define DIO_u8PIN7           7

u8 DIO_u8SETPinDirection(u8 COPY_u8Port,u8 COPY_u8Pin, u8 COPY_u8Direction);

u8 DIO_u8SETPortDirection(u8 COPY_u8Port,u8 COPY_u8Direction);

u8 DIO_u8SETPinValue(u8 COPY_u8Port,u8 COPY_u8Pin,u8 COPY_u8Value);

u8 DIO_u8SETPortValue(u8 COPY_u8Port,u8 COPY_u8Value);

u8 DIO_u8GetPinValue(u8 COPY_u8Port,u8 COPY_u8Pin, u8* COPY_pu8Value);


#endif
