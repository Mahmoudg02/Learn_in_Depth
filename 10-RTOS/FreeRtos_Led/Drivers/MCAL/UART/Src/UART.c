
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART.c
 *       Author:  MAshr  
 *   	   Date:  7 Nov 2022
 *       Module:
 *		  Brief:
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
//#include "Std_Types.h"
#include "STM32F103_UART.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
UART_Config_t * Gptr_UartCnfig  =NULL ;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : void MCAL_UART_Init(USART_REG_t* USARTx ,UART_Config_t * UART_Config)
 * \Description     : initialize UARTx module
 * \Sync\Async      : Synchronous
 * \Reentrancy      :  Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Parameters (in) : UART_Config_t * UART_Config  >> configuration structure of uart
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_Init(USART_REG_t* USARTx ,UART_Config_t * UART_Config)
{
	Gptr_UartCnfig = UART_Config ;

	uint32_t PCLK , BRR ,Div_M100 ;

	//1- enable uart CLK
	if(USARTx==USART1)
		RCC_USART1_CLK_EN() ;
	else if (USARTx==USART1)
		RCC_USART2_CLK_EN() ;
	else if (USARTx==USART3)
		RCC_USART3_CLK_EN() ;

	//	2- Bit 13 UE: USART enable
	//	0: USART prescaler and outputs disabled
	//	1: USART enabled
	USARTx ->CR1 |= (1<<13) ;

	//3- set mode of uart
	USARTx->CR1 &=~(0b11<<2);
	USARTx->CR1|=((UART_Config->Mode)<<2) ;

	//4- set Pay load length
	//	Bit 12 M: Word length
	//	0: 1 Start bit, 8 Data bits, n Stop bit
	//	1: 1 Start bit, 9 Data bits, n Stop bit
	USARTx->CR1&=~(1<<12) ;
	USARTx->CR1|=((UART_Config->PayLoadLenght)<<12) ;

	//5- set Parity
	//	Bit 10 PCE: Parity control enable
	//	0: Parity control disabled
	//	1: Parity control enabled
	//	Bit 9 PS: Parity selection
	//	0: Even parity
	//	1: Odd parity
	USARTx->CR1|=((UART_Config->Parity)<<9) ;

	//6- select stop bits
	//	Bits 13:12 STOP: STOP bits
	//	00: 1 Stop bit
	//	01: 0.5 Stop bit
	//	10: 2 Stop bits
	//	11: 1.5 Stop bit
	//	The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
	USARTx->CR2 |= ((UART_Config->StopBits)<<12) ;

	//7- set flow control
	//	Bit 9 CTSE: CTS enable
	//	0: CTS hardware flow control disabled
	//	1: CTS mode enabled,
	//	Bit 8 RTSE: RTS enable
	//	0: RTS hardware flow control disabled
	//	1: RTS interrupt enabled,
	USARTx->CR3&=~(0b11<<8) ;
	USARTx->CR3|=((UART_Config->FlowCTRL)<<8) ;

	//8-set Baud Rate
	if (USARTx == USART1)
	{
		PCLK = MCAL_RCC_GetFreq_PCLK2()*1000000 ;
	}else
	{
		PCLK = MCAL_RCC_GetFreq_PCLK1()*1000000 ;
	}
	Div_M100 = (PCLK*100/(UART_Config->BaudRate * 16) );
	BRR = (uint32_t)((PCLK/(UART_Config->BaudRate * 16) )<<4) ;
	BRR|=(uint32_t)(((Div_M100%100)*16)/100) ;

	USARTx->BRR =BRR ;
	//9- enable interrupt
	//10- enable NVIC
	if (UART_Config->IRQ_EN != UART_IRQ_NONE)
	{
		USARTx->CR1 |= UART_Config->IRQ_EN ;

		if (USARTx==USART1)
		{
			NVIC_IRQ37_USART1_EN() ;
		}else if (USARTx==USART2)
		{
			NVIC_IRQ38_USART2_EN() ;
		}else if (USARTx==USART3)
		{
			NVIC_IRQ39_USART3_EN() ;
		}
	}

	MCAL_UART_GPIO_SetPins( USARTx) ;
}

/******************************************************************************
 * \Syntax          : void MCAL_UART_RST(USART_REG_t* USARTx)
 * \Description     : reset UARTx module
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_RST(USART_REG_t* USARTx){

	if (USARTx==USART1)
	{
		NVIC_IRQ37_USART1_DIS() ;
		RCC_USART1_CLK_RST() ;
	}else if (USARTx==USART2)
	{
		NVIC_IRQ38_USART2_DIS() ;
		RCC_USART2_CLK_RST() ;
	}else if (USARTx==USART3)
	{
		NVIC_IRQ39_USART3_DIS() ;
		RCC_USART3_CLK_RST() ;
	}
}

/******************************************************************************
 * \Syntax          : void MCAL_UART_RST(USART_REG_t* USARTx)
 * \Description     : reset UARTx module
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Parameters (in) : uint16_t *DataBuff >> address of data buffer
 * \Parameters (in) : Polling_Mechanism Polling_State >> method of check if it interrupt or polling
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_SendData(USART_REG_t* USARTx ,uint16_t *DataBuff,Polling_Mechanism Polling_State ){

	// check polling or interrupt mechanism
	if (Polling_State == PollingEN)
	{
		while(!(USARTx->SR&(1<<7)));
	}
	//check if 8 bit or 9 bit data
	//	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	//	the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	//	because it is replaced by the parity.

	if (Gptr_UartCnfig->PayLoadLenght==UART_9BitData)
	{
		USARTx->DR = ((*DataBuff)&(uint16_t)0x01FF );

	}else if (Gptr_UartCnfig->PayLoadLenght==UART_8BitData)
	{
		USARTx->DR = ((*DataBuff)&(uint8_t)0xFF );
	}
}

/******************************************************************************
 * \Syntax          : void MCAL_UART_Wait_TC(USART_REG_t* USARTx)
 * \Description     : wait until the data transmitted
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_Wait_TC(USART_REG_t* USARTx){
	while (!(USARTx->SR&(1<<6))) ;
}

/******************************************************************************
 * \Syntax          : void MCAL_UART_RecieveData(USART_REG_t* USARTx ,uint16_t *DataBuff,Polling_Mechanism Polling_State )
 * \Description     : receive data from uart
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Parameters (in) : uint16_t *DataBuff >> address of data buffer
 * \Parameters (in) : Polling_Mechanism Polling_State >> method of check if it interrupt or polling
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_RecieveData(USART_REG_t* USARTx ,uint16_t *DataBuff,Polling_Mechanism Polling_State ){

	if (Polling_State==PollingEN)
	{
		while(!(USARTx->SR&(1<<5)));
	}
	if (Gptr_UartCnfig->Parity == UART_PARITY_NONE)
	{
		if (Gptr_UartCnfig->PayLoadLenght==UART_8BitData)
		{*DataBuff= (uint16_t)((USARTx->DR)&0xFF ) ;
		}else {
			*DataBuff=(uint16_t)((USARTx->DR)&0x01FF ) ;
		}
	}else
	{
		//	When receiving with the parity enabled, the value read in the MSB bit is the received parity bit
		if (Gptr_UartCnfig->PayLoadLenght==UART_8BitData)
		{*DataBuff= (uint16_t)((USARTx->DR)&0x7F ) ;
		}else {
			*DataBuff= (uint16_t)((USARTx->DR)&0xFF ) ;
		}
	}

}

/******************************************************************************
 * \Syntax          : void MCAL_UART_GPIO_SetPins(USART_REG_t* USARTx)
 * \Description     : configure pins to AFIO recommendation
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : USART_REG_t* USARTx >> instant of UART
 * \Return value:   : none
 *******************************************************************************/
void MCAL_UART_GPIO_SetPins(USART_REG_t* USARTx){

	GPIO_PinConfig_t uartPin ;

	if (USARTx==USART1)
	{
		//		PA10 USART1_RX
		//		PA9 USART1_TX
		//		PA11 USART1_CTS
		//		PA12 USART1_RTS

		//TX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
		uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
		uartPin.GPIO_PIN =GPIO_PIN9 ;
		MCAL_GPIO_Init(GPIOA,&uartPin) ;
		//RX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
		uartPin.GPIO_PIN =GPIO_PIN10 ;
		MCAL_GPIO_Init(GPIOA,&uartPin) ;

		if (Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//RTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
			uartPin.GPIO_PIN =GPIO_PIN12 ;
			MCAL_GPIO_Init(GPIOA, &uartPin) ;
		}
		if(Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_CTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//CTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			uartPin.GPIO_PIN =GPIO_PIN11 ;
			MCAL_GPIO_Init(GPIOA, &uartPin) ;
		}

	}else if (USARTx==USART2)
	{
		//		PA3 USART2_RX
		//		PA2 USART2_TX
		//		PA0 USART2_CTS
		//		PA1 USART2_RTS

		//TX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
		uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
		uartPin.GPIO_PIN =GPIO_PIN2 ;
		MCAL_GPIO_Init(GPIOA,&uartPin) ;
		//RX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
		uartPin.GPIO_PIN =GPIO_PIN3 ;
		MCAL_GPIO_Init(GPIOA,&uartPin) ;

		if (Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//RTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
			uartPin.GPIO_PIN =GPIO_PIN1 ;
			MCAL_GPIO_Init(GPIOA, &uartPin) ;
		}
		if(Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_CTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//CTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			uartPin.GPIO_PIN =GPIO_PIN0 ;
			MCAL_GPIO_Init(GPIOA, &uartPin) ;
		}

	}else if (USARTx==USART3)
	{
		//		PB11 USART3_RX
		//		PB10 USART3_TX
		//		PB13 USART3_CTS
		//		PB14 USART3_RTS

		//TX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
		uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
		uartPin.GPIO_PIN =GPIO_PIN10 ;
		MCAL_GPIO_Init(GPIOB,&uartPin) ;
		//RX
		uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
		uartPin.GPIO_PIN =GPIO_PIN11 ;
		MCAL_GPIO_Init(GPIOB,&uartPin) ;

		if (Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//RTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			uartPin.GPIO_SPEED =GPIO_SPEED_10M ;
			uartPin.GPIO_PIN =GPIO_PIN14 ;
			MCAL_GPIO_Init(GPIOB, &uartPin) ;
		}
		if(Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_CTS || Gptr_UartCnfig->FlowCTRL == UART_FLOWCTRL_RTS_CTS)
		{
			//CTS
			uartPin.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			uartPin.GPIO_PIN =GPIO_PIN13 ;
			MCAL_GPIO_Init(GPIOB, &uartPin) ;
		}

	}
}


//ISR

void USART1_IRQHandler(){
	Gptr_UartCnfig->ptr_IRQ_CallBack();
}
void USART2_IRQHandler(){
	Gptr_UartCnfig->ptr_IRQ_CallBack();

}
void USART3_IRQHandler(){
	Gptr_UartCnfig->ptr_IRQ_CallBack();

}
/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
