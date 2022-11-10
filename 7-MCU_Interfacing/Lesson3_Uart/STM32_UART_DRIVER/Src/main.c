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

//////////////////////////////////////////////////////////////////////////////////
uint8_t ch ;

static void _delay_ms(int  loop)
{
	for(int j = 0 ; j< loop ; j++)
	for (int i =0 ;i < 250 ;i++);
}

void uartIRQcallBack(void)
{
	MCAL_UART_RecieveData(USART1, &ch, PollingDis) ;
	//MCAL_UART_SendData(USART1,  &ch, PollingEN) ;

}

int main(void)
{
	clk_init() ;

	UART_Config_t uart1cnfig ;
	uart1cnfig.BaudRate = UART_BAUDRATE_115200 ;
	uart1cnfig.FlowCTRL = UART_FLOWCTRL_NONE ;
	uart1cnfig.IRQ_EN = UART_IRQ_RXNE ;
	uart1cnfig.Mode = UART_MODE_RX_TX ;
	uart1cnfig.Parity = UART_PARITY_NONE ;
	uart1cnfig.PayLoadLenght = UART_8BitData ;
	uart1cnfig.StopBits = UART_StopBits_1 ;
	uart1cnfig.ptr_IRQ_CallBack = uartIRQcallBack;

	MCAL_UART_Init(USART1, &uart1cnfig) ;
	MCAL_UART_GPIO_SetPins(USART1) ;
	while (1){
		MCAL_UART_SendData(USART1, &ch, PollingEN) ;
		_delay_ms(100);

	}
	return 0;
}
