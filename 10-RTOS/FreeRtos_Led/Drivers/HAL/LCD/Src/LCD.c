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
/*----------------------------------------------------------------
--------------------- Private Constants ---------------------------
----------------------------------------------------------------*/


/*----------------------------------------------------------------
--------------------- Delay Function -------------------------
----------------------------------------------------------------*/
static void _delay_ms(int  loop)
{
	for (int i =0 ;i < 250 ;i++);
}

/*----------------------------------------------------------------
--------------------- Private Variable Definitions ---------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Variable Definitions ----------------
----------------------------------------------------------------*/
#define LCD_PORT GPIOA

LCD_Connections_t LCD_obj={
		GPIOA,
		{GPIOA,GPIO_PIN10,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_10M},
		{GPIOA,GPIO_PIN9,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_10M},
		{GPIOA,GPIO_PIN8,GPIO_MODE_OUTPUT_PP,GPIO_SPEED_10M},
};

GPIO_PinConfig_t LCD_DATA_PIN ={
		GPIOA ,
		GPIO_PIN0 ,
		GPIO_MODE_OUTPUT_PP ,
		GPIO_SPEED_10M,
};
/*----------------------------------------------------------------
--------------------- Private Functions Prototypes ---------------
----------------------------------------------------------------*/
void LCD_kick();
void LCD_is_Busy();
void LCD_DATA_DIR(uint8_t mode);
/*----------------------------------------------------------------
--------------------- Public Function Definitions ----------------
----------------------------------------------------------------*/
void LCD_init(){

	_delay_ms(20) ;
	MCAL_GPIO_Init(LCD_PORT,&(LCD_obj.lcd_En)) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_En.GPIO_PIN, GPIO_PIN_LOW);


	MCAL_GPIO_Init(LCD_PORT,&LCD_obj.lcd_RS) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RS.GPIO_PIN, GPIO_PIN_LOW);

	MCAL_GPIO_Init(LCD_PORT,&LCD_obj.lcd_RW) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RW.GPIO_PIN, GPIO_PIN_LOW);

#ifdef LCD_8BIT_MODE_EN

	LCD_DATA_DIR(GPIO_MODE_OUTPUT_PP);
	_delay_ms(15);
	LCD_send_command(LCD_MODE_8BIT_2LINES) ;
#endif

#ifdef LCD_4BIT_MODE_EN
	(*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+DIR_OFFSET))|=(0x0F<<HALF_PORT_SHIFT) ;
	_delay_ms(15);
	LCD_send_command(LCD_object,LCD_RETURN_HOME);
	LCD_send_command(LCD_object,LCD_MODE_4BIT_2LINES) ;

#endif
	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK) ;
	LCD_send_command(LCD_ENTERY_INC);
	LCD_send_command(LCD_FIRST_LINE);
	LCD_send_command(LCD_CLR_SCREEN) ;
}


void LCD_send_command(uint8_t command )
{
#ifdef LCD_8BIT_MODE_EN
	LCD_is_Busy();
	uint16_t temp =command ;
	temp|=MCAL_GPIO_ReadPort(LCD_PORT)&0xFF00 ;
	MCAL_GPIO_WritePort(LCD_PORT,temp) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RS.GPIO_PIN, GPIO_PIN_LOW) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RW.GPIO_PIN, GPIO_PIN_LOW) ;
	LCD_kick() ;
#endif
#ifdef LCD_4BIT_MODE_EN
	LCD_is_Busy(LCD_object);
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)&=~(0x0F<<HALF_PORT_SHIFT) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)|=(((command&0xF0)>>4)<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,LOW) ;
	LCD_kick(LCD_object) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)&=~(0x0f<<HALF_PORT_SHIFT) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)|=((command&0x0F)<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,LOW) ;
	LCD_kick(LCD_object) ;
#endif
}

void LCD_send_char( uint8_t data )
{
#ifdef LCD_8BIT_MODE_EN

	LCD_is_Busy( );
	uint16_t temp =data ;
	temp|=MCAL_GPIO_ReadPort(LCD_PORT)&0xFF00 ;
	MCAL_GPIO_WritePort(LCD_PORT,temp) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RW.GPIO_PIN, GPIO_PIN_LOW) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RS.GPIO_PIN, GPIO_PIN_HIGH) ;
	LCD_kick( ) ;


#endif
#ifdef LCD_4BIT_MODE_EN
	LCD_is_Busy(LCD_object);
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)&=~(0x0F<<HALF_PORT_SHIFT) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)|=(((data&0xF0)>>4)<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,HIGH) ;
	LCD_kick(LCD_object) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)&=~(0x0F<<HALF_PORT_SHIFT) ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+PORT_OFFSET)|=((data&0x0F)<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,HIGH) ;
	LCD_kick(LCD_object) ;

#endif

}

void LCD_clear_screen(){
	LCD_send_command(LCD_CLR_SCREEN);
}
void LCD_send_string( uint8_t* string )
{
	uint8_t count =0 ;
	LCD_is_Busy( );
	while(*string)
	{
		LCD_send_char(*string++) ;
		count ++ ;
		if(count==16)
		{
			LCD_goto(1,0) ;
		}else if (count ==32)
		{
			count = 0 ;
			LCD_goto(0,0);
		}
	}
}


void LCD_goto(uint8_t line ,uint8_t position)
{
	if((line==1||line==0)&&(position>=0&&position<16))
	{
		uint8_t cmd = line==1?(LCD_SECOND_LINE + position ):(LCD_FIRST_LINE + position) ;
		LCD_send_command(cmd) ;
	}

}
void LCD_send_number( uint16_t num)
{
	uint8_t temp[10] ;
	sprintf((char*)temp,(char*)"%d",num);
	LCD_send_string(temp) ;
}
/*----------------------------------------------------------------
--------------------- Private Functions Definitions --------------
----------------------------------------------------------------*/
void LCD_is_Busy(){
#ifdef LCD_8BIT_MODE_EN
	LCD_DATA_DIR(GPIO_MODE_INPUT_FLOATING);
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RW.GPIO_PIN, GPIO_PIN_HIGH) ;
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RS.GPIO_PIN, GPIO_PIN_LOW) ;
	LCD_kick();
	//while(MCAL_GPIO_ReadPin(LCD_PORT, GPIO_PIN7)==0){asm volatile("NOP");} ;
	LCD_DATA_DIR(GPIO_MODE_OUTPUT_PP);
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_RW.GPIO_PIN, GPIO_PIN_LOW) ;
#endif

#ifdef LCD_4BIT_MODE_EN
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+DIR_OFFSET)&=~(0x0F<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,HIGH) ;
	GPIO_WritePin(LCD_object.lcd_RS.port,LCD_object.lcd_RS.pin,LOW) ;
	while(GPIO_ReadPin(LCD_object.DataPort,7)==0){asm volatile("NOP");} ;
	*(volatile uint8_t *)(Get_Port_Addr(LCD1_PORT)+DIR_OFFSET)|=(0x0f<<HALF_PORT_SHIFT) ;
	GPIO_WritePin(LCD_object.lcd_RW.port,LCD_object.lcd_RW.pin,LOW) ;

#endif
}

void LCD_kick(){
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_En.GPIO_PIN, GPIO_PIN_HIGH) ;
	_delay_ms(50);
	MCAL_GPIO_WritePin(LCD_PORT, LCD_obj.lcd_En.GPIO_PIN, GPIO_PIN_LOW) ;

}

void LCD_DATA_DIR(uint8_t mode){

	LCD_DATA_PIN.GPIO_MODE=mode ;
	LCD_DATA_PIN.GPIO_PIN = GPIO_PIN0 ;
	for (int i=0 ;i<8 ;i++){
		MCAL_GPIO_Init(LCD_PORT, &LCD_DATA_PIN) ;
		LCD_DATA_PIN.GPIO_PIN =LCD_DATA_PIN.GPIO_PIN<< 1;
	}
}


/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/
