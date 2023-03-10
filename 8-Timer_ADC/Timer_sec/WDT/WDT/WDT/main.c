/*
 * WDT.c
 *
 * Created: 10/7/2021 12:15:55 AM
 * Author : Marco
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT, BIT)			PORT |= (1<< BIT)
#define RESET_BIT(PORT, BIT)		PORT &= ~(1<<BIT)
#define TOG_BIT(PORT, BIT)			PORT ^= (1<<BIT)
#define GET_BIT(PORT, BIT)			PORT & (1<<BIT)

#define LED_DDR DDRD
#define LED_PORT PORTD


void WDT_ON()
{
	WDTCR = (1 << WDP0) | (1 << WDP1) | (1 << WDP2) | (1 << WDE);
}

void WDT_OFF()
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

int main(void)
{
    /* Replace with your application code */
	LED_DDR |= 0xC0;
	
    while (1) 
    {
		WDT_ON();
		_delay_ms(100);
		TOG_BIT(LED_PORT, 6);
		WDT_OFF();
    }
}

