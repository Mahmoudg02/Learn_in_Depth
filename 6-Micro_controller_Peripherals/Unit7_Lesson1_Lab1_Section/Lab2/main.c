/*
 * Lab2.c
 *
 * Created: 04/10/2022 11:50:53
 * Author : MAshr
 */ 

#include "LIB/GPIO.h"
#include "LIB/S_seg.h"


int main(void)
{
    GPIO_init();
// 	GPIO_WritePin_Dir(Port_D,5,PIN_OUTPUT);
// 	GPIO_WritePin_Dir(Port_D,6,PIN_OUTPUT);
// 	GPIO_WritePin_Dir(Port_D,7,PIN_OUTPUT);
	
	GPIO_WritePin(Port_D,5,HIGH);
	GPIO_WritePin(Port_D,6,HIGH);
	GPIO_WritePin(Port_D,7,HIGH);

	GPIO_WritePort_DIR(0b11110000,Port_D);
	
	s_seg_init();
	s_seg_write(5);
    while (1) 
    {
		if (GPIO_ReadPin(Port_D,0)==1)
			GPIO_WritePin(Port_D,5,LOW);

    }
	
	return 0 ;
}

