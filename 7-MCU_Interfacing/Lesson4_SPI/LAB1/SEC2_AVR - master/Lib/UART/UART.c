/*
 * UART.c
 *
 * Created: 05/11/2022 00:46:49
 *  Author: MAshr
 */ 

#include "UART.h"
#include <avr/interrupt.h>

#define UDRE  5 
#define U2X  1
#define RXC 7
#define TXC 6 

#define TXEN 3 
#define RXEN 4

#define RXCIE 7 
#define TXCIE 6

#define Defualt_Stop '\r'

void MCAL_UART_Init(){
	
	// setup the frame form 
	
	// setup the BuadRate 
	myUBRRL =51 ;
	CLR_BIT(myUCSRA ,U2X) ;
	//Setup the interrupts 
	
	//Enable the module 
	SET_BIT(myUCSRB,TXEN) ;
	SET_BIT(myUCSRB ,RXEN) ;
}

void MCAL_UART_Send(u8 data){
	while (!GET_BIT(myUCSRA,UDRE)) ;
	myUDR = data ;
}
u8 MCAL_UART_Recieve(void)
{
	while (!GET_BIT(myUCSRA,RXC)) ;
	return myUDR ;
}
void MCAL_UART_SendString(u8* ptrData) 
{	u8 i=0  ;
	while(ptrData[i])
	{
		MCAL_UART_Send(ptrData[i]);	
		i++ ;
	}
}
void MCAL_UART_recString(u8* DataBuff){
	u8 i =0 ;
do 
{
	DataBuff[i] = MCAL_UART_Recieve() ;
	i++ ;
} while (DataBuff[i-1]!='\r');

DataBuff[i-1] ='\0' ;
}

void MCAL_UART_TXIEN(){
	SET_BIT(myUCSRB ,TXCIE) ;
}
void MCAL_UART_TXIDIS(){
	CLR_BIT(myUCSRB,TXCIE) ;
}
void MCAL_UART_RXIEN() {
	SET_BIT(myUCSRB,RXCIE) ;
}
void MCAL_UART_RXDIS(){
	CLR_BIT(myUCSRB,RXCIE) ;
}


static u8* ptr_Async ;


void MCAL_UART_SendAsync(u8* DataBaff){
	SET_BIT(mySREG,7) ;

	MCAL_UART_TXIEN() ;
	if(DataBaff[0]!=0)
	MCAL_UART_Send(DataBaff[0]) ;

	ptr_Async = DataBaff ;

	
}

ISR(USART_TXC_vect){
	
	static u8 i = 1 ;
	if (ptr_Async[i])
	{
		myUDR =ptr_Async[i] ;
		i++ ;
	}else
	{
		i = 1 ;
				myUDR =ptr_Async[i] ;

	}
}
