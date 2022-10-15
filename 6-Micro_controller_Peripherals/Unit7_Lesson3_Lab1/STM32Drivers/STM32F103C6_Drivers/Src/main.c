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

#include "../Drivers/Includes/STM32F103_GPIO.h"
#include "../Drivers/Includes/STM32F103C6.h"

//this project to control GPIO Ports A,B with LEDs on PB1,PB13 and push button on PA1 ,PA13 for blue Bill Board
// Verified simulation in proteus



void clk_init(void ){

	// enable CLK for port A
	RCC_GPIOA_CLK_EN() ;
	//enable CLK for Port B
	RCC_GPIOB_CLK_EN() ;

}
////////////////////////////////////////////////////////////////////////////////
void GPIO_init (void ){

	// configure port A for 2 push button input floating . MODE 0x00 CNF0x01
	// A1
	GPIO_PinConfig_t pinCnfg  ;

	pinCnfg.GPIO_MODE=GPIO_MODE_FLOATING_INPUT ;
	pinCnfg.GPIO_PIN =GPIO_PIN1 ;
	MCAL_GPIO_Init(GPIOA, &pinCnfg);
	// A13
	pinCnfg.GPIO_MODE=GPIO_MODE_FLOATING_INPUT ;
	pinCnfg.GPIO_PIN =GPIO_PIN13 ;
	MCAL_GPIO_Init(GPIOA, &pinCnfg);

	// configure port B for 2 Led output pins Push_Pull. MODE 0x01 CNF0x00
	//B1
	pinCnfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinCnfg.GPIO_PIN =GPIO_PIN1 ;
	pinCnfg.GPIO_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCnfg);

	// B13
	pinCnfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinCnfg.GPIO_PIN =GPIO_PIN13 ;
	pinCnfg.GPIO_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCnfg);
}
//////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	clk_init() ;
	GPIO_init();
	/* Loop forever */

	while (1){
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1)==GPIO_PIN_LOW)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1)==GPIO_PIN_LOW);//for single press
		}
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN13)==GPIO_PIN_HIGH)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN13);
			//while ((GPIOA_IDR&(1<<1))==0);//for single press
		}
		for (int i = 0 ;i < 2000 ;i++);
	}
	return 0;
}
