#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SEVENSEG_PRIVATE.h"
#include "SEVENSEG_INTERFACE.h"
#include "SEVENSEGMANT_cfg.h"
#include "DIO_INTERFACE.h"


u16 SEVENSEG[10]={zero,one,two,three,four,five,six,seven,eight,nine};


void SEVSEGMENT_VidDisplayment (u8 COPY_U8PORT,u8 COPY_U8NUM)
{
	#if SEG_TYPE==COMMON_CATHOD
	DIO_VidsetportValue(COPY_U8PORT,SEVENSEG[COPY_U8NUM]);
	#elif SEG_TYPE==COMMON_ANOD
	DIO_VidsetportValue(COPY_U8PORT,~(SEVENSEG[COPY_U8NUM]));
	#else
		#error "wrong input"
	
	#endif
	
}
