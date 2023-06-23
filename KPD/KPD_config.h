#ifndef      _KPD_CONFIG_H_
#define      _KPD_CONFIG_H_

#define NO_PressedKey  0xff
#define KPD_Arr_Nums {{'1','2','3','4'},{'5','6','7','8'},{'9','10','11','12'},{'13','14','15','16'}}

#define ROW_Num     4
#define COL_Num     4

#define ROW_PORT    DIO_u8PORTC
#define ROW1_PIN    DIO_u8PIN5
#define ROW2_PIN    DIO_u8PIN4
#define ROW3_PIN    DIO_u8PIN3
#define ROW4_PIN    DIO_u8PIN2

#define COL_PORT    DIO_u8PORTD
#define COL1_PIN    DIO_u8PIN7
#define COL2_PIN    DIO_u8PIN6
#define COL3_PIN    DIO_u8PIN5
#define COL4_PIN    DIO_u8PIN3

#endif
