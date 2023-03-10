/*
 * STM32F103_SPI.h
 *
 *  Created on: 17 Nov 2022
 *      Author: MAshr
 */

#ifndef DRIVERS_MCAL_SPI_STM32F103_SPI_H_
#define DRIVERS_MCAL_SPI_STM32F103_SPI_H_

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
//CR1.Bit 2 MSTR: Master selection
//0: Slave configuration
//1: Master configuration

#define SPI_MODE_MASTER			1
#define SPI_MODE_SLAVE			0

/*--------------------------
---@SPI_Communication_Mode ---
---------------------------*/
//CR1.Bit 15 BIDIMODE: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected
//Bit 14 BIDIOE: Output enable in bidirectional mode
//This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
//0: Output disabled (receive-only mode)
//1: Output enabled (transmit-only mode)
//Bit 10 RXONLY: Receive only
//This bit combined with the BIDImode bit selects the direction of transfer in 2-line
//unidirectional mode. This bit is also useful in a multislave system in which this particular
//slave is not accessed, the output from the accessed slave is not corrupted.
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive-only mode)

#define SPI_DIR_2LINE_TXRX					0
#define SPI_DIR_2LINE_RXONLY				1
#define SPI_DIR_1LINE_RXONLY				2
#define SPI_DIR_1LINE_TXONLY				3


/*--------------------------
---@Frame_Format_Define ---
---------------------------*/
//CR1.Bit 7 LSBFIRST: Frame format
//0: MSB transmitted first
//1: LSB transmitted first
#define SPI_FORMAT_MSB_First 								0
#define SPI_FORMAT_LSB_First								1
/*--------------------------
---@Data_Size_Define ---
---------------------------*/
//CR1.Bit 11 DFF: Data frame format
//0: 8-bit data frame format is selected for transmission/reception
//1: 16-bit data frame format is selected for transmission/reception
#define SPI_DATASIZE_8 								0
#define SPI_DATASIZE_16								1

/*--------------------------
---@ClkPol_Define ---
---------------------------*/
//CR1.Bit1 CPOL: Clock polarity
//0: CK to 0 when idle
//1: CK to 1 when idle
#define SPI_CLKPOL_LOW								0
#define SPI_CLKPOL_HIGH								1

/*--------------------------
---@ClkPha_Define ---
---------------------------*/
//CR1.Bit 0 CPHA: Clock phase
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge
#define SPI_CLKPHA_1ST_DATA_CAPTURE					0
#define SPI_CLKPHA_2ST_DATA_CAPTURE					1

/*--------------------------
---@NSS_Define ---
---------------------------*/
//Bit 9 SSM: Software slave management
//When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
//0: Software slave management disabled
//1: Software slave management enabled
//Bit 8 SSI: Internal slave select
//This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
//NSS pin and the IO value of the NSS pin is ignored.
#define SPI_NSS_SW_DIS						0
#define SPI_NSS_SLAVE_SW_RST				2
#define SPI_NSS_SLAVE_SW_SET				3
//cr2.Bit 2 SSOE: SS output enable
//0: SS output is disabled in master mode and the cell can work in multi master configuration
//1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
//in a MultiMaster environment.
#define SPI_NSS_HW_OP_DIS					4
#define SPI_NSS_HW_OP_EN					5

/*--------------------------
---@PreScaler_Define ---
---------------------------*/
//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256
#define SPI_PRESCALER_D2					0
#define SPI_PRESCALER_D4					1
#define SPI_PRESCALER_D8					2
#define SPI_PRESCALER_D16					3
#define SPI_PRESCALER_D32					4
#define SPI_PRESCALER_D64					5
#define SPI_PRESCALER_D128					6
#define SPI_PRESCALER_D256					7


/*--------------------------
---@SPI_IRQ_Define ---
---------------------------*/
//CR2.Bits 5:7
//Bit 7 TXEIE: Tx buffer empty interrupt enable
//0: TXE interrupt masked
//1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
//Bit 6 RXNEIE: RX buffer not empty interrupt enable
//0: RXNE interrupt masked
//1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
//Bit 5 ERRIE: Error interrupt enable
//This bit controls the generation of an interrupt when an error condition occurs (CRCERR, OVR, MODF in SPI mode and UDR, OVR in I2S mode).
//0: Error interrupt is masked
//1: Error interrupt is enabled
#define SPI_IRQ_NONE						0
#define SPI_IRQ_TXEIE						4
#define SPI_IRQ_RXNEIE						2
#define SPI_IRQ_ERRIE						1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{
	uint8_t TXE		:1 ; // TX Buffer Empty
	uint8_t RXNE	:1 ; // RX Buffer Not Empty
	uint8_t ERR		:1 ; // SPI Error
	uint8_t    		:5 ;
}SPI_IRQ_SRC_t;

typedef struct {
	uint8_t 		Mode ; 						// this parameter specifies the mode of SPI master or slave
												// this parameter must be set based on @ref SPI_Mode_Define
	uint8_t 		Communication_Mode; 		// this parameter specifies the SPI communication mode
												// this parameter must be set based on @ref SPI_Communication_Mode
	uint8_t			Frame_Format;				// this parameter specifies the SPI frame format
												// this parameter must be set based on @ref Frame_Format_Define
	uint8_t			Data_Size;					// this parameter specifies the SPI Data_Size
												// this parameter must be set based on @ref Data_Size_Define
	uint8_t			ClkPol;						// this parameter specifies the SPI clock polarity
												// this parameter must be set based on @ref ClkPol_Define
	uint8_t			ClkPha;						// this parameter specifies the SPI clock phase
												// this parameter must be set based on @ref ClkPha_Define
	uint8_t			NSS;						// this parameter select NSS signal managed by software or hardware
												// this parameter must be set based on @ref NSS_Define
	uint8_t			PreScaler;					// this parameter select prescaler vale for the SPI module
												// this parameter must be set based on @ref PreScaler_Define
												// must to configure RCC  first
	uint8_t			IRQ_EN;						// this parameter select if interrupt is enabled
												// this parameter must be set based on @ref SPI_IRQ_Define
	void (*ptr_IRQ_CallBack)(SPI_IRQ_SRC_t spi_irq_src ) ;// pointer to ISR function

}SPI_Config_t;

 typedef enum {
	SPIPollingDis,
	SPIPollingEN
}SPI_Polling_Mechanism;// Mechanism


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void MCAL_SPI_Init(SPI_REG_t *SPIx ,SPI_Config_t* SPIConfig) ;
void MCAL_SPI_RST(SPI_REG_t *SPIx) ;
void MCAL_SPI_GPIO_SET_PINS(SPI_REG_t *SPIx);

void MCAL_SPI_SendData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism Polling_State);
void MCAL_SPI_ReceiveData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism Polling_State);
void MCAL_SPI_TXRX(SPI_REG_t *SPIx ,uint16_t *ptTXRXBuffer ,SPI_Polling_Mechanism Polling_State);

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/



#endif /* DRIVERS_MCAL_SPI_STM32F103_SPI_H_ */
