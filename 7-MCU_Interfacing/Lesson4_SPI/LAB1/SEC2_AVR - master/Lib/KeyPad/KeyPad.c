/*
 * KeyPad.c
 *
 * Created: 15/10/2022 22:09:25
 *  Author: MAshr
 */ 

#include "KeyPad.h"

int KeyPad_R[]={R0 ,R1 ,R2 ,R3} ;
int KeyPad_C[]={C0 ,C1 ,C2 ,C3} ;
	
	
	
u8 ConvToChar(u8 i  ,u8 j);




void KeyPad_Init()
{
	GPIO_WritePort_DIR(KEYPAD_PORT,KEYPAD_PORT_DIR) ;
	GPIO_WritePort(KEYPAD_PORT ,0xFF) ; //make the output pint HIGH , and make the inputs pulled up .
	
}


u8 KeyPad_GetChar()
{
	u8 i , j;
	
	for (i =0 ; i<4 ;i++)
	{
		GPIO_WritePort(KEYPAD_PORT ,0xFF);
		GPIO_WritePin(KEYPAD_PORT,KeyPad_C[i],LOW) ;
		
		for (j=0 ;j< 4 ;j++)
		{	
			if (GPIO_ReadPin(KEYPAD_PORT,KeyPad_R[j])==0)
			{	
				while(GPIO_ReadPin(KEYPAD_PORT,KeyPad_R[j])==0);		
				return ConvToChar(i,j);			
			}
			_delay_ms(10);
		}
	}
return 'N'	;
}

u8 ConvToChar(u8 i  ,u8 j){
	
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
