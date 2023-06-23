/********************************************************************************/
/********************************************************************************/
/********************     Author : YOUSSEF    ***********************************/
/********************     Layer :  HAL       ***********************************/
/********************     SWC :    DIO        ***********************************/
/********************     VERION : 1.00       ***********************************/
/********************************************************************************/
/********************************************************************************/

#ifndef    _SSD_INTERFACE_H_
#define    _SSD_INTERFACE_H_


#define    SSD_u8Num0Display      0
#define    SSD_u8Num1Display      0b00000001
#define    SSD_u8Num2Display      0b00000010
#define    SSD_u8Num3Display      0b00000011
#define    SSD_u8Num4Display      0b00000100
#define    SSD_u8Num5Display      0b00000101
#define    SSD_u8Num6Display      0b00000110
#define    SSD_u8Num7Display      0b00000111
#define    SSD_u8Num8Display      0b00010000
#define    SSD_u8Num9Display      0b00010001

#define    SSD_u8CommonAnode       1
#define    SSD_u8CommonCathod      0

typedef struct
{
	u8 SSD_u8CommonType;
	u8 SSD_u8Port;
	u8 SSD_u8EnablePort;
	u8 SSD_u8EnablePin;
}SSD_Type;

u8 SSD_u8SetNumber(u8 COPY_u8Number,SSD_Type* COPY_SSD);



#endif
