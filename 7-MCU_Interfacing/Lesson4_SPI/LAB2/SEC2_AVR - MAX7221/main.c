/*
 * GccApplication3.c
 *
 * Created: 05/08/2022 18:27:02
 * Author : MAshr
 */ 

#include "Lib/GPIO/GPIO.h"
#include "Lib/common/Bit_man.h"
#include "Lib/LED_MATRIX/LED_MATRIX.h"
#include "Lib/PushButton/PushButton.h"
#include "Lib/S_seg/S_seg.h"
#include "Lib/LCD/LCD.h"
#include "Lib/UART/UART.h"
#include "Lib/SPI/SPI.h"
#include "Lib/MAX7221/MAX7221.h"
#define F_CPU 1000000UL

#include <util/delay.h>

int data=0 ;
int main(void)
{	
	MAX_7sig_Init() ;


while(1){
	
	for (int i = 0 ; i< 9 ;i++)
	{
		MAX_7sig_excute(i,i);
		_delay_ms(400);
	}

}
return 0 ;
}

