#ifndef SEVENSEGMENT_PROG_H_
#define SEVENSEGMENT_PROG_H_

#define LOW 0
#define HIGH 1

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_CFG.h"
#include <AVR/delay.h>

void KEYPAD_VIDIntialize (u8 COPY_U8PORT)
{
	DIO_VidsetportDirection(COPY_U8PORT ,0b11110000);// coulms from bin 4 to 7 and rows from bin 0 to  pin 3
	DIO_VidsetportValue(COPY_U8PORT , 0b11111111);//row->pull up inputs and coulmns->output
}
u8 KEYPAD_U8GetPressedKey (u8 COPY_U8PORT)
{
	u8 LOC_U8key=50;
	u8 LOC_U8pressed=1;
	
	for (u8 c=0;c<COL;c++)
	{ DIO_VidsetpinValue(COPY_U8PORT,c+4,LOW);
		for (u8 r=0;r<ROW;r++)
		{LOC_U8pressed=DIO_U8GetPinValue(COPY_U8PORT,r);
			if (LOC_U8pressed==LOW)
			{
				LOC_U8key=(4*r)+c ;
		while (LOC_U8pressed==LOW)
		{
			LOC_U8pressed=DIO_U8GetPinValue(COPY_U8PORT,r);

		}
						_delay_ms(30);

		}
		
		}
			DIO_VidsetpinValue(COPY_U8PORT,c+4,HIGH);

	}
	return LOC_U8key;
	}
	
		
		


		
		
		

#endif
