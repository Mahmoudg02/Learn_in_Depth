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
#include "KeyPad.h"
#include "LCD.h"
#include "STM32F103_EXTI.h"
#include "STM32F103_UART.h"
#include "Stm32F103_RCC.h"
#include "STM32F103_SPI.h"
#include "STM32F103_I2C.h"
#include "EEPROM.h"


//#define MCU_MASTER

//#define MCU_SLAVE

void clk_init(void ){

	// enable CLK for port A
	RCC_GPIOA_CLK_EN() ;
	//enable CLK for Port B
	RCC_GPIOB_CLK_EN() ;
	//enable AFIO CLK
	RCC_AFIO_CLK_EN() ;
	//enable I2C CLK
	RCC_I2C1_CLK_EN() ;

}
////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////


//static void _delay_ms(int  loop)
//{
//	for(int j = 0 ; j< loop ; j++)
//		for (int i =0 ;i < 250 ;i++);
//}



int main(void)
{


	clk_init() ;

	/* Initialization of EEPROM */
	HAL_EEPROM_Init();

	/* =============== Test Case 1 =============== */

	uint8_t CH1_To_Write[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	uint8_t CH2_To_Read[7] = {0};

	HAL_EEPROM_Write_NBytes(0xAF, CH1_To_Write, 7);
	HAL_EEPROM_Read_NBytes(0xAF, CH2_To_Read, 7);

	/* =============== Test Case 2 =============== */

	CH1_To_Write[0] = 0xA;
	CH1_To_Write[1] = 0xB;
	CH1_To_Write[2] = 0xC;
	CH1_To_Write[3] = 0xD;

	HAL_EEPROM_Write_NBytes(0xFFF, CH1_To_Write, 4);
	HAL_EEPROM_Read_NBytes(0xFFF, CH2_To_Read, 4);

	/* Loop For Ever */
	while(1){


		/* =============== Test Case 1 =============== */

		uint8_t CH1_To_Write[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
		uint8_t CH2_To_Read[7] = {0};

		HAL_EEPROM_Write_NBytes(0xAF, CH1_To_Write, 7);
		HAL_EEPROM_Read_NBytes(0xAF, CH2_To_Read, 7);

		/* =============== Test Case 2 =============== */

		CH1_To_Write[0] = 0xA;
		CH1_To_Write[1] = 0xB;
		CH1_To_Write[2] = 0xC;
		CH1_To_Write[3] = 0xD;

		HAL_EEPROM_Write_NBytes(0xFFF, CH1_To_Write, 4);
		HAL_EEPROM_Read_NBytes(0xFFF, CH2_To_Read, 4);

		/* Loop For Ever */

	}
	return 0;
}
