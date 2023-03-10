

#include "STM32F103_GPIO.h"


	GPIO_PinConfig_t pin13 ;

void led_init(void){
	RCC_GPIOC_CLK_EN() ;
	pin13.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	pin13.GPIO_PIN = GPIO_PIN13 ;
	pin13.GPIO_PORT = GPIOC ;
	pin13.GPIO_SPEED = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOC,&pin13) ;
	
}

void led_on(void){
	
	MCAL_GPIO_WritePin(GPIOC,pin13.GPIO_PIN ,GPIO_PIN_LOW);
}

void led_off(void){
	
	MCAL_GPIO_WritePin(GPIOC,pin13.GPIO_PIN ,GPIO_PIN_HIGH);
}