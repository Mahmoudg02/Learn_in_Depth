/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mahmoud Ashraf
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "STM32F103C6.h"
#include "STM32F103_GPIO.h"
//#include "KeyPad.h"
#include "LCD.h"
#include "STM32F103_EXTI.h"

//this project to control GPIO Ports A,B with LEDs on PB1,PB13 and push button on PA1 ,PA13 for blue Bill Board
// Verified simulation in proteus


void clk_init(void ){

	// enable CLK for port A
	RCC_GPIOA_CLK_EN() ;
	//enable CLK for Port B
	RCC_GPIOB_CLK_EN() ;
	//enable AFIO CLK
	RCC_AFIO_CLK_EN() ;



}
////////////////////////////////////////////////////////////////////////////////
void GPIO_init (void ){

//	GPIO_PinConfig_t pinCnfg  ;
//
//	pinCnfg.GPIO_MODE=GPIO_MODE_INPUT_FLOATING ;
//	pinCnfg.GPIO_PIN =GPIO_PIN1 ;
//	MCAL_GPIO_Init(GPIOA, &pinCnfg);
//	// A13
//	pinCnfg.GPIO_MODE=GPIO_MODE_INPUT_PU ;
//	pinCnfg.GPIO_PIN =GPIO_PIN13 ;
//	MCAL_GPIO_Init(GPIOA, &pinCnfg);
//
//	// configure port B for 2 Led output pins Push_Pull. MODE 0x01 CNF0x00
//	//B1
//	pinCnfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
//	pinCnfg.GPIO_PIN =GPIO_PIN1 ;
//	pinCnfg.GPIO_SPEED =GPIO_SPEED_10M;
//	MCAL_GPIO_Init(GPIOB, &pinCnfg);
//
//	// B13
//	pinCnfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
//	pinCnfg.GPIO_PIN =GPIO_PIN13 ;
//	pinCnfg.GPIO_SPEED =GPIO_SPEED_10M;
//	MCAL_GPIO_Init(GPIOB, &pinCnfg);
//
//	MCAL_GPIO_WritePin(GPIOA ,pinCnfg.GPIO_PIN, GPIO_PIN_HIGH);

}
//////////////////////////////////////////////////////////////////////////////////

static void _delay_ms(int  loop)
{
	for(int j = 0 ; j< loop ; j++)
	for (int i =0 ;i < 250 ;i++);
}

void interrupt(void ){
	LCD_send_string((uint8_t*)"interrupt B9") ;
	_delay_ms(500) ;
}

int main(void)
{
	clk_init() ;
	LCD_init()  ;
//	GPIO_init();
	//KeyPad_Init() ;
	/* Loop forever */
//	LCD_send_char('S');

	EXTI_PinCfg_t exti9 ;
	exti9.EXTI_PIN = EXTI9PB9 ;
	exti9.EXTI_IRQ_EN = EXTI_Enable ;
	exti9.EXTI_Trigger = EXTI_Trigger_Rising ;
	exti9.P_IRQ_CallBack = interrupt ;
	MCAL_EXTI_GPIO_Init(&exti9) ;


	while (1){
		//KeyPad_GetChar();
		LCD_clear_screen() ;
	}
	return 0;
}
