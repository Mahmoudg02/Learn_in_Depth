/*
 * LCD.h
 *
 * Created: 11/08/2022 00:26:01
 *  Author: MAshr
 */ 

/*----------------------------------------------------------------
--------------------- Header Guard -------------------------------
----------------------------------------------------------------*/
#ifndef LCD_H_
#define LCD_H_


/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/
#define F_CPU 1000000UL
#include "util/delay.h"
#include "../GPIO/GPIO.h"
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------
--------------------- Public Function Prototypes ----------------
----------------------------------------------------------------*/
//#define LCD_8BIT_MODE_EN
#define LCD_4BIT_MODE_EN
#define HALF_PORT_SHIFT 4
/*----------------------------------------------------------------
--------------------- Public Constants ---------------------------
----------------------------------------------------------------*/

#define LCD_CLR_SCREEN				0x01
#define LCD_RETURN_HOME				0x02
#define LCD_ENTERY_DEC				0x04
#define LCD_ENTERY_DEC_SHIFT		0x05
#define LCD_ENTERY_INC				0x06
#define LCD_ENTERY_INC_SHIFT		0x07
#define LCD_OFF						0x08
#define LCD_DISP_ON					0x0c
#define LCD_DISP_ON_CURSOR_BLINK	0x0f
#define LCD_DISP_ON_CURSOR			0x0e
#define LCD_DISP_ON_BLINK			0x0d
#define LCD_SHIFT_CERSOR_LEFT		0x10
#define LCD_SHIFT_CERSOR_RIGHT		0x14
#define LCD_SHIFT_DISP_LEFT			0x18
#define LCD_SHIFT_DISP_RIGHT		0x1c
#define LCD_MODE_8BIT_2LINES		0x38
#define LCD_MODE_4BIT_2LINES		0x28
#define LCD_FIRST_LINE				0x80
#define LCD_SECOND_LINE				0xC0
/*----------------------------------------------------------------
--------------------- Public Data Types --------------------------
----------------------------------------------------------------*/
#define LCD1_PORT Port_A
#define LCD2_PORT Port_C


typedef struct {
	int DataPort ;
	PIN_CONNECTION_t lcd_Enable ;
	PIN_CONNECTION_t lcd_RW ;
	PIN_CONNECTION_t lcd_RS ;
}LCD_Connections_t;

extern LCD_Connections_t LCD1_object , LCD2_object ;
/*----------------------------------------------------------------
--------------------- Public Variable Declarations ---------------
----------------------------------------------------------------*/
// #define LCD1_PORT Port_A 
// LCD_Connections_t LCD1_object={
// 	LCD1_PORT,
// 	{Port_B ,3},
// 	{Port_B ,2},
// 	{Port_B ,1},
// };

/*----------------------------------------------------------------
--------------------- Public Function Prototypes ----------------
----------------------------------------------------------------*/
void LCD_init(LCD_Connections_t LCD_object) ;
void LCD_send_command(LCD_Connections_t LCD_object , u8 command );
void LCD_send_char(LCD_Connections_t LCD_object , u8 data ) ;
void LCD_send_string(LCD_Connections_t LCD_object , u8* string ) ;
void LCD_goto(LCD_Connections_t LCD_object,u8 line ,u8 position);
void LCD_clear_screen(LCD_Connections_t LCD_object);
void LCD_send_number(LCD_Connections_t LCD2_object ,int num) ;

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/




#endif /* LCD_H_ */