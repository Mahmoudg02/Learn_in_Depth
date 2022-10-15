/*
 * LCD_KeyPad_Driver.c
 *
 * Created: 11/10/2022 13:42:14
 * Author : MAshr
 */ 

#include <avr/io.h>
#include "LIB/LCD.h"


int main(void)
{	
	LCD_init(LCD1_object) ;
	LCD_send_number(LCD1_object, -26) ;
//	LCD_init(LCD2_object) ;

		//LCD_send_char(LCD2_object,'B') ;

    /* Replace with your application code */
    while (1) 
    {
		
		asm volatile("NOP") ;
		_delay_ms(100);
		
    }
}

