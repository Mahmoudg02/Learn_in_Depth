/*
 * Timer.c
 *
 * Created: 10/7/2021 11:34:11 AM
 * Author : Marco
 */ 

#define F_CPU 8000000UL
#include "MCAL/Timers.h"

extern uint8_t u8_TOVNumber;

void TOIE_Callback()
{
	 static uint8_t counter = 0 ; 
	TIMER0_GetOverflowValue(&counter) ;
	PORTA = counter ;
	
	
}

void CMIE_Callback()
{
	static uint8_t counter = 0 ;
	TIMER0_GetCounterValue(&counter) ;
	PORTC = counter ;
}

int main(void)
{
	DDRA = 0xFF;
	DDRC = 0xFF ;
	sei();
	TIMER0_CALLBACK_CompareMatch_INTERRUPT(CMIE_Callback);
	TIMER0_CALLBACK_Overflow_INTERRUPT(TOIE_Callback);

	STIMER0_CONFIG config = {NORMAL, OCIE_ENABLE, TOIE_ENABLE, PRESCALING_CLK1024};
	TIMER0_SetCompareValue(0xF0);
    TIMER0_Init(&config);
	
	
    while (1) 
    {
    }
}

