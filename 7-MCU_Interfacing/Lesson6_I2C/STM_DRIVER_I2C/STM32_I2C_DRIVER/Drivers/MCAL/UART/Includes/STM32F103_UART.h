/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART.h
 *       Author:  MAshr  
 *         Date:  7 Nov 2022
 *       Module:
 *        Brief:
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DRIVERS_UART_UART_H_
#define DRIVERS_UART_UART_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STM32F103C6.h"
#include "STM32F103_GPIO.h"
#include "Stm32F103_RCC.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*--------------------------
---@UART_Mode_Define---
---------------------------*/
#define UART_MODE_OFF			0
#define UART_MODE_RX			1
#define UART_MODE_TX			2
#define UART_MODE_RX_TX			3

/*--------------------------
---@UART_BAUDRATE_Define ---
---------------------------*/
#define UART_BAUDRATE_2400							2400
#define UART_BAUDRATE_9600							9600
#define UART_BAUDRATE_19200							19200
#define UART_BAUDRATE_57600							57600
#define UART_BAUDRATE_115200						115200
#define UART_BAUDRATE_230400						230400
#define UART_BAUDRATE_460800						460800
#define UART_BAUDRATE_921600						921600
#define UART_BAUDRATE_2250000						2250000

/*--------------------------
---@UART_PayLoadLenth_Define ---
---------------------------*/
#define UART_8BitData 								0
#define UART_9BitData								1

/*--------------------------
---@UART_ParityType_Define ---
---------------------------*/
#define UART_PARITY_EVEN							2
#define UART_PARITY_ODD								3
#define UART_PARITY_NONE							0

/*--------------------------
---@UART_StopBits_Define ---
---------------------------*/
#define UART_StopBits_1								0 //1 bit
#define UART_StopBits_p5							1 // .5 bit
#define UART_StopBits_1p5							2 // 1.5 bit
#define UART_StopBits_2								3 // 2 bit

/*--------------------------
---@UART_FlowCTRL_Define ---
---------------------------*/
#define UART_FLOWCTRL_NONE							0
#define UART_FLOWCTRL_RTS							1
#define UART_FLOWCTRL_CTS							2
#define UART_FLOWCTRL_RTS_CTS						3

/*--------------------------
---@UART_IQR_Define ---
---------------------------*/
//refers to direct position in their registers
#define UART_IRQ_NONE								(uint32_t)0
#define UART_IRQ_TXE								(uint32_t)(1<<7)
#define UART_IRQ_TC									(uint32_t)(1<<6)
#define UART_IRQ_RXNE								(uint32_t)(1<<5)
#define UART_IRQ_PE									(uint32_t)(1<<8)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct {
	uint8_t 		Mode ; 			// this parameter specifies the mode of usart tx or rx or both
									// this parameter must be set based on @ref UART_Mode_Define
	uint32_t 		BaudRate; 		// this parameter specifies the UART Baud Rate
									// this parameter must be set based on @ref UART_BAUDRATE_Define
	uint8_t			PayLoadLenght;	// this parameter specifies the UART Data length
									// this parameter must be set based on @ref PayLoadLength_Define
	uint8_t			Parity;			// this parameter specifies the UART Parity Type
									// this parameter must be set based on @ref ParityType_Define
	uint8_t			StopBits;		// this parameter specifies the UART number of stop bits
									// this parameter must be set based on @ref StopBits_Define
	uint8_t			FlowCTRL;		// this parameter select if the flow control enabled
									// this parameter must be set based on @ref FlowCTRL_Define
	uint8_t			IRQ_EN;			// this parameter select which interrupt is enabled
									// this parameter must be set based on @ref UART_IQR_Define
	void (*ptr_IRQ_CallBack)(void) ;// pointer to ISR function
}UART_Config_t;


typedef enum {
	PollingDis,
	PollingEN

}Polling_Mechanism;// Mechanism


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void MCAL_UART_Init(USART_REG_t* USARTx ,UART_Config_t * UART_Config);
void MCAL_UART_RST(USART_REG_t* USARTx);
void MCAL_UART_GPIO_SetPins(USART_REG_t* USARTx) ;

void MCAL_UART_SendData(USART_REG_t* USARTx ,uint16_t *DataBuff,Polling_Mechanism Polling_State ) ;
void MCAL_UART_RecieveData(USART_REG_t* USARTx ,uint16_t *DataBuff,Polling_Mechanism Polling_State ) ;

void MCAL_UART_Wait_TC(USART_REG_t* USARTx) ;

#endif  /* DRIVERS_UART_UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
