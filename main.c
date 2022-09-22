#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_INTERFACE.h"
#include "SEVENSEG_INTERFACE.h"
#define A 0
#define B 1
#define C 2
#define D 3

#include <avr/delay.h>



void main(void)
{
	KEYPAD_VIDIntialize(A);
	u8 key;
	DIO_VidsetportDirection(B,0b11111111);
	DIO_VidsetportDirection(C,0b11111111);

	while(1)
	{
key= KEYPAD_U8GetPressedKey(A);
if (key!=50)
{ if (key<10)
	{
		SEVSEGMENT_VidDisplayment(B,key);
		SEVSEGMENT_VidDisplayment(C,0);
	_delay_ms(500);
	}
	
	else if (key>=10)
	{ int u,t=0;
u=key%10;
t=(key/10)%10;
SEVSEGMENT_VidDisplayment(C,t);
SEVSEGMENT_VidDisplayment(B,u);
		_delay_ms(500);
	}

}



	}

}
