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


//#define MCU_MASTER
#define MCU_SLAVE

//#define MCU_SLAVE

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

uint8_t ch ;
void uart1CallBack(void){
#ifdef MCU_MASTER
	// recieve data from uart
	MCAL_UART_RecieveData(USART1, (uint16_t*)&ch, PollingDis) ;
	MCAL_UART_SendData(USART1, (uint16_t*)&ch, PollingEN) ;

	// send data by spi
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 0) ;
	MCAL_SPI_TXRX(SPI1, (uint16_t*)&ch, SPIPollingEN);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1) ;
#endif
}

void spi1CallBack(SPI_IRQ_SRC_t interruptSrc){
#ifdef MCU_SLAVE
	if (interruptSrc.RXNE ){
		ch = 0xAF ;
		MCAL_SPI_TXRX(SPI1, (uint16_t*)&ch, SPIPollingDis) ;
		MCAL_UART_SendData(USART1, (uint16_t*)&ch, PollingEN) ;
	}
#endif
}

int main(void)
{

	clk_init() ;

	UART_Config_t uart1 ;
	uart1.BaudRate = UART_BAUDRATE_115200 ;
	uart1.FlowCTRL = UART_FLOWCTRL_NONE ;
	uart1.IRQ_EN =UART_IRQ_RXNE ;
	uart1.ptr_IRQ_CallBack = uart1CallBack;
	uart1.Mode = UART_MODE_RX_TX ;
	uart1.Parity = UART_PARITY_NONE ;
	uart1.PayLoadLenght =UART_8BitData ;
	uart1.StopBits = UART_StopBits_1 ;
	MCAL_UART_Init(USART1, &uart1) ;



	SPI_Config_t spi1 ;
	//common config
	spi1.ClkPha = SPI_CLKPHA_2ST_DATA_CAPTURE ;
	spi1.ClkPol = SPI_CLKPOL_HIGH ;
	spi1.Data_Size = SPI_DATASIZE_8 ;
	spi1.Frame_Format =SPI_FORMAT_MSB_First ;
	spi1.PreScaler =SPI_PRESCALER_D8 ;
	spi1.Communication_Mode = SPI_DIR_2LINE_TXRX ;

#ifdef MCU_MASTER



	spi1.Mode = SPI_MODE_MASTER ;
	spi1.IRQ_EN = SPI_IRQ_NONE  ;
	spi1.NSS =SPI_NSS_SLAVE_SW_SET ;
	spi1.ptr_IRQ_CallBack =NULL ;



	// configure pin PA4 to be output for ss
	GPIO_PinConfig_t SSpin ;
	SSpin.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	SSpin.GPIO_PIN =GPIO_PIN4 ;
	SSpin.GPIO_PORT  =GPIOA ;
	SSpin.GPIO_SPEED =GPIO_SPEED_10M ;

	MCAL_GPIO_Init(GPIOA, &SSpin) ;
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1) ;

#endif


#ifdef MCU_SLAVE
	spi1.Mode = SPI_MODE_SLAVE ;
	spi1.IRQ_EN = SPI_IRQ_RXNEIE  ;
	spi1.NSS =SPI_NSS_SW_DIS ;
	spi1.ptr_IRQ_CallBack =spi1CallBack ;

#endif

	MCAL_SPI_Init(SPI1, &spi1) ;
	while (1){


	}
	return 0;
}
