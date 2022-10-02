
#include <stdint.h>

#define RCC_base 0x40021000
#define RCC_CR *((volatile uint32_t * )(RCC_base + 0x00))
#define RCC_CFGR *((volatile uint32_t * )(RCC_base + 0x04))
#define RCC_APB2ENR *((volatile uint32_t * )(RCC_base + 0x18))


#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


void clk_init(void ){
	//set PLL * 8
	RCC_CFGR |=(0b0110<<18);
	// select PLL CLK
	RCC_CFGR |=(0b10<<0);
	// PLL ON
	RCC_CR|=(1<<24);
	// set APB2 CLK /4
	RCC_CFGR|=(0b101<<11) ;
	// set APB 1 CLK /2
	RCC_CFGR|=(0b100<<8);
	// set AHB to none pre-scaler
	RCC_CFGR &=~(0b111<<4);


	// enable CLK for port A
	RCC_APB2ENR|=(1<<2) ;

	while (!((RCC_CR>>25)&1));

}

void GPIO_init (void ){
	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000 ;
}

int main(void)
{
	clk_init() ;
	GPIO_init();
	/* Loop forever */
	while (1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
	return 0 ;

}
