/*
 * LED_MATRIX.c
 *
 * Created: 07/08/2022 00:36:41
 *  Author: MAshr
 */ 

#include"LED_MATRIX.h"
#include"../GPIO/GPIO.h"

// #define F_CPU 1000000UL      
// #include <util/delay.h>    // just for testing and will be  replaced by timer 



#define LedMatrixMuxPort  Port_A
#define LedMatrixDataPort Port_D
/************************************************************************/
/* Data of char                                                         */
/************************************************************************/

char LED_MATRIX_DATA[2][8]={
			{0b0000000,0b11111111,0b00010001,0b00010001,0b00010001,0b00010001,0b11111111,0b00000000},
		  	{0b00000000,0b01111111,0b01001001,0b01001001,0b01001001,0b01001001,0b00110110,0b00000000}
};

/************************************************************************
 * Initialization Function 
*************************************************************************/
u8 LED_MATRIX_INIT(void){
	
	GPIO_WritePort_DIR(PORT_HIGH,LedMatrixMuxPort) ;
	GPIO_WritePort_DIR(PORT_HIGH,LedMatrixDataPort) ;
	return No_Error ;
	
}
/************************************************************************
 * Display char 
*************************************************************************/
u8 LED_MATRIX_DISP(u8 Displayed_Char ){
	u8 LED_MATRIX_MUX ;
	
	for (LED_MATRIX_MUX =0 ;LED_MATRIX_MUX<8 ;LED_MATRIX_MUX++ )
	{
			GPIO_WritePort(~(LED_MATRIX_DATA[Displayed_Char][LED_MATRIX_MUX]),LedMatrixDataPort);
			GPIO_WritePort(1<<LED_MATRIX_MUX,LedMatrixMuxPort);
			
//replaced by timer functions 			
//			_delay_ms(200);
	}

return No_Error ;
	
}