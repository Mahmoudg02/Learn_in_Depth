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
#define F_CPU 1000000UL

#include <util/delay.h>


int main(void)
{	
MCAL_UART_Init() ;
// MCAL_UART_Send('a');
// MCAL_UART_Send('a');
// MCAL_UART_Send('a');
// MCAL_UART_Send('a');
// MCAL_UART_Send('a');

LCD_init(LCD1_object);
MCAL_UART_SendAsync("mahmoud") ;
//MCAL_UART_SendString((u8*)"mahmoud") ;
u8 buff[200] ;
while(1){
	


for (u8 i = 0; i<10 ;i++)
{
	LCD_send_number(LCD1_object,i) ;
	_delay_ms(500) ;
	LCD_clear_screen(LCD1_object) ;
	LCD_goto(LCD1_object,0,0) ;
}

}
return 0 ;
}

