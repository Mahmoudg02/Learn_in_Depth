/*
 * LCD.c
 *
 * Created: 11/08/2022 00:25:48
 *  Author: MAshr
 */ 
/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/
#include "LCD.h"
#include "Bit_man.h"
#include "Platform_Types.h"
#include "GPIO.h"
#include "LCD_connections.h"
/*----------------------------------------------------------------
--------------------- Private Constants ---------------------------
----------------------------------------------------------------*/


/*----------------------------------------------------------------
--------------------- Private Data Types -------------------------
----------------------------------------------------------------*/


/*----------------------------------------------------------------
--------------------- Private Variable Definitions ---------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Variable Definitions ----------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Private Functions Prototypes ---------------
----------------------------------------------------------------*/
void LCD_kick(LCD_Connections_t LCD1_object);
void LCD_is_Busy(LCD_Connections_t LCD_object);


/*----------------------------------------------------------------
--------------------- Public Function Definitions ----------------
----------------------------------------------------------------*/
void LCD_init(LCD_Connections_t LCD_object){
	_delay_ms(20) ;
	GPIO_WritePin_Dir(LCD_object.lcd_Enable.port ,LCD_object.lcd_Enable.pin,PIN_OUTPUT) ;
	GPIO_WritePin(LCD_object.lcd_Enable.port ,LCD_object.lcd_Enable.pin,LOW);
	
	GPIO_WritePin_Dir(LCD_object.lcd_RS.port ,LCD_object.lcd_RS.pin,PIN_OUTPUT) ;
	GPIO_WritePin(LCD_object.lcd_RS.port ,LCD_object.lcd_RS.pin,LOW) ;

	GPIO_WritePin_Dir(LCD_object.lcd_RW.port ,LCD_object.lcd_RW.pin,PIN_OUTPUT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port ,LCD_object.lcd_RW.pin,LOW) ;

	GPIO_WritePort_DIR(LCD_object.DataPort ,PORT_OUTPUT) ;

	
	_delay_ms(15);
	
	LCD_send_command(LCD_object,LCD_MODE_8BIT_2LINES) ;
	LCD_send_command(LCD_object,LCD_DISP_ON_CURSOR_BLINK) ;
	LCD_send_command(LCD_object,LCD_ENTERY_INC);
	LCD_send_command(LCD_object , LCD_CLR_SCREEN) ;



	
}


void LCD_send_command(LCD_Connections_t LCD_object , u8 command )
{
	LCD_is_Busy(LCD_object);
	GPIO_WritePort(LCD_object.DataPort,command) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,LOW) ;
	LCD_kick(LCD_object) ;
	
}

void LCD_send_char(LCD_Connections_t LCD_object , u8 data )
{
	LCD_is_Busy(LCD_object);
	GPIO_WritePort(LCD_object.DataPort,data) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,HIGH) ;
	LCD_kick(LCD_object) ;
	
}

void LCD_send_string(LCD_Connections_t LCD_object , u8* string )
{
	u8 count =0 ;
	LCD_is_Busy(LCD_object);
	while(*string)
	{
		LCD_send_char(LCD_object ,*string++) ;	
		count ++ ;
		if(count==16)
		{
			LCD_goto(LCD_object,1,0) ;
		}else if (count ==32)
		{
			count = 0 ;
			LCD_goto(LCD_object,0,0);
		}
	}
}

void LCD_clear_screen(LCD_Connections_t LCD_object)
{
	LCD_send_command(LCD_object,LCD_CLR_SCREEN) ;
}

void LCD_goto(LCD_Connections_t LCD_object,u8 line ,u8 position)
{
	if((line==1||line==0)&&(position>=0&&position<16))
	{
	u8 cmd = line==1?(LCD_SECOND_LINE + position ):(LCD_FIRST_LINE + position) ;
	LCD_send_command(LCD_object ,cmd) ;
	}
	
}
void LCD_send_number(LCD_Connections_t LCD2_object ,int num)
{
	char volatile temp[10] ;
	sprintf(temp,"%d",num);
	LCD_send_string(LCD1_object ,temp) ;
}
/*----------------------------------------------------------------
--------------------- Private Functions Definitions --------------
----------------------------------------------------------------*/
void LCD_is_Busy(LCD_Connections_t LCD_object){
	
	GPIO_WritePort_DIR(LCD_object.DataPort ,PORT_INPUT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,HIGH) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,LOW) ;

 while(GPIO_ReadPin(LCD_object.DataPort,7)==0){
// 	asm volatile("NOP");
 	} ;
	GPIO_WritePort_DIR(LCD_object.DataPort ,PORT_OUTPUT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;

}

void LCD_kick(LCD_Connections_t LCD_object){
	GPIO_WritePin(LCD_object.lcd_Enable.port ,LCD_object.lcd_Enable.pin,HIGH) ;
	_delay_ms(20);
	GPIO_WritePin(LCD_object.lcd_Enable.port ,LCD_object.lcd_Enable.pin,LOW) ;


}

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/