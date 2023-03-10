/*
 * KeyPad.c
 *
 * Created: 15/10/2022 22:09:25
 *  Author: MAshr
 */ 

#include "KeyPad.h"

uint16_t KeyPad_R[]={R0 ,R1 ,R2 ,R3} ;
uint16_t KeyPad_C[]={C0 ,C1 ,C2 ,C3} ;
	
	
	
uint8_t ConvToChar(uint8_t i  ,uint8_t j);

GPIO_PinConfig_t KeyPad_pins={
		KEYPAD_PORT  ,
		GPIO_PIN0 ,
		GPIO_MODE_OUTPUT_PP ,
		GPIO_SPEED_10M
};

static void _delay_ms(int  loop)
{
	for (int i =0 ;i < 250 ;i++);
}


void KeyPad_Init()
{
	for(int i =0 ;i < 4 ; i++)
	{
		KeyPad_pins.GPIO_PIN=KeyPad_C[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &KeyPad_pins);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[i], GPIO_PIN_HIGH);

	}
	KeyPad_pins.GPIO_MODE=GPIO_MODE_INPUT_FLOATING;
	for(int i =0 ;i < 4 ; i++)
	{
		KeyPad_pins.GPIO_PIN=KeyPad_R[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &KeyPad_pins);
	}

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFFFF);

//make the output pint HIGH , and make the inputs pulled up .
	
}


uint8_t KeyPad_GetChar()
{
	uint8_t i , j;

	for (i =0 ; i<4 ;i++)
	{
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[i], GPIO_PIN_LOW);
		for (j=0 ;j< 4 ;j++)
		{
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, KeyPad_R[j])==GPIO_PIN_LOW)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, KeyPad_R[j])==GPIO_PIN_LOW);
				return ConvToChar(i,j);
			}
			_delay_ms(10);
		}
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[i], GPIO_PIN_HIGH);
		_delay_ms(10);

	}
return 'N'	;
}

uint8_t ConvToChar(uint8_t i  ,uint8_t j){
	
	if(i==0)
	{
		switch(j){
		case 0 : return '7' ;
		break ;
		case 1: return '4' ;
		break ;
		case 2 : return '1' ;
		break ;
		case 3: return 'O' ;
		break ;
	}
	}else if (i==1)
	{
		switch(j){
		case 0 : return '8' ;
		break ;
		case 1: return '5' ;
		break ;
		case 2 : return '2' ;
		break ;
		case 3: return '0' ;
		break ;
	}
	}else if (i==2)
	{
		switch(j){
		case 0 : return '9' ;
		break ;
		case 1: return '6' ;
		break ;
		case 2 : return '3' ;
		break ;
		case 3: return '=' ;
		break ;
	}
	}else if (i==3)
	{
		switch(j){
		case 0 : return '/' ;
		break ;
		case 1: return '*' ;
		break ;
		case 2 : return '-' ;
		break ;
		case 3: return '+' ;
		break ;
		}
	}
	
	return 'N' ;
}
