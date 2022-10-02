/*
 * Unit6_Lesson4_SEC_LAB.c
 *
 * Created: 02/10/2022 19:24:37
 * Author : MAshr
 */ 


#define F_CPU 1000000ul
#include "util/delay.h"
//#include <avr/io.h>
#include <avr/interrupt.h>


#define SREG *(volatile uint8_t *)(0x05F)
#define MCUCR *(volatile uint8_t *)(0x055)
#define MCUCSR *(volatile uint8_t *)(0x054)
#define GICR *(volatile uint8_t *)(0x05B)

#define GPIO_base 0x20
#define GPIO_PORTD  *(volatile uint8_t *)(GPIO_base + 0x12)
#define GPIO_DDRD  *(volatile uint8_t *)(GPIO_base + 0x11)

void GPIO_init(void ){

	GPIO_DDRD|=(0b111<<5);
}


void interrupt_init(void)
{
	// enable global interrupt
	SREG|=(1<<7) ;
	//Interrupt0 for level change
	MCUCR|=(0b01<<0) ;
	//Interrupt1 for rising
	MCUCR|=(0b11<<2) ;
	//interrupt 2  rising
	MCUCSR &=~(0b1<<6) ;
	// enable interrupt mask
	GICR |=(0b111<<5) ;

}

int main(void)
{
	
	
GPIO_init();
interrupt_init();

    while(1)
    {
		GPIO_PORTD &= ~((1<<5) | (1<<6) | (1<<7)) ;
	    _delay_ms(1000) ;
    }
}



ISR(INT0_vect)
{
	GPIO_PORTD |= 1<<5;
	_delay_ms(1000) ;
}

ISR(INT1_vect)
{
	GPIO_PORTD |= 1<<6;
	_delay_ms(1000) ;
}

ISR(INT2_vect)
{
	GPIO_PORTD |= 1<<7 ;
	_delay_ms(1000) ;
}


