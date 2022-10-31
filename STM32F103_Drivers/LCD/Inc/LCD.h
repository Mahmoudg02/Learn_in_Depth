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

#include <stdio.h>
#include <stdlib.h>
#include "STM32F103_GPIO.h"
/*----------------------------------------------------------------
--------------------- Public Function Prototypes ----------------
----------------------------------------------------------------*/
#define LCD_8BIT_MODE_EN
//#define LCD_4BIT_MODE_EN
//#define HALF_PORT_SHIFT 4
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

typedef struct {
	GPIO_REG_t* Lcd_DataPort ;
	GPIO_PinConfig_t lcd_En ;
	GPIO_PinConfig_t lcd_RW ;
	GPIO_PinConfig_t lcd_RS ;
}LCD_Connections_t;

extern LCD_Connections_t LCD_obj ;
/*----------------------------------------------------------------
--------------------- Public Variable Declarations ---------------
----------------------------------------------------------------*/

// LCD_Connections_t LCD1_object={
// 	LCD_PORT,
// 	{Port_C ,6},
// 	{Port_C ,7},
// 	{Port_C ,8},
// };

/*----------------------------------------------------------------
--------------------- Public Function Prototypes ----------------
----------------------------------------------------------------*/
void LCD_init() ;
void LCD_send_command(uint8_t command );
void LCD_send_char( uint8_t data ) ;
void LCD_send_string( uint8_t* string ) ;
void LCD_goto(uint8_t line ,uint8_t position);
void LCD_clear_screen();
void LCD_send_number(uint16_t num) ;

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/




#endif /* LCD_H_ */
