
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SPI.c
 *       Author:  MAshr
 *   	   Date:  22 Nov 2022
 *       Module:
 *		  Brief:
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STM32F103_SPI.h"


/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define SPI1_Index				0
#define SPI2_Index				1

#define		 	 SPI1_Port 	GPIOA
#define		     SPI1_NSS  	GPIO_PIN4
#define			 SPI1_SCK  	GPIO_PIN5
#define			 SPI1_MISO 	GPIO_PIN6
#define			 SPI1_MOSI 	GPIO_PIN7

#define		 	 SPI2_Port 	GPIOB
#define		     SPI2_NSS 	GPIO_PIN12
#define			 SPI2_SCK 	GPIO_PIN13
#define			 SPI2_MISO 	GPIO_PIN14
#define			 SPI2_MOSI 	GPIO_PIN15

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static SPI_Config_t * Gptr_SPICnfig[2]  ={NULL,NULL} ;
SPI_Config_t G_SPICnfig1 ;
SPI_Config_t G_SPICnfig2 ;

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
 * \Syntax          : void MCAL_SPI_Init(SPI_REG_t *SPIx ,SPI_Config_t* SPIConfig)
 * \Description     : Initialize SPIx module
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : SPI_REG_t *SPIx >> instant of SPI
 * \Parameters (in) : SPI_Config_t* SPIConfig  >> configuration structure of SPI
 * \Return value:   : none
 *******************************************************************************/
void MCAL_SPI_Init(SPI_REG_t *SPIx ,SPI_Config_t* SPIConfig){

	//1- safety method
	uint16_t temCr1 = 0 ;
	uint16_t temCr2 = 0 ;

	if (SPIx == SPI1){
		//1- global pointer to configuration
		G_SPICnfig1 = * SPIConfig ;
		Gptr_SPICnfig[SPI1_Index] = & G_SPICnfig1 ;

		//2 enable clock of spi 1
		RCC_SPI1_CLK_EN() ;

	}else if (SPIx == SPI2)
	{
		//1- global pointer to configuration
		G_SPICnfig2 = * SPIConfig ;
		Gptr_SPICnfig[SPI2_Index] = &G_SPICnfig2 ;

		//2 enable clock of spi 1
		RCC_SPI2_CLK_EN() ;
	}

	//3- select data size of frame
	temCr1 |=((SPIConfig->Data_Size)<<11) ;

	//4- select clock polarity configuration
	temCr1 |=((SPIConfig->ClkPol)<<1) ;

	// 5- select clock phase of frame
	temCr1 |= ((SPIConfig->ClkPha)<<0);

	// 6- select frame format least or most bit will send at beginning
	temCr1 |= (SPIConfig->Frame_Format << 7) ;

	//7 - hardware mode or software
	if (SPIConfig->NSS < 4){
		temCr1 |= (SPIConfig->NSS << 8) ;
	}else if (SPIConfig->NSS >=4 ) {
		temCr2 |=(1<<2) ;
	}

	// 8 - select mode
	if (SPIConfig->Mode == SPI_MODE_MASTER)
	{
		temCr1 |= (SPIConfig->Mode << 2) ;
		// 9- select baud rate
		temCr1 |= (SPIConfig->PreScaler << 3 ) ;

	}else if (SPIConfig ->Mode == SPI_MODE_SLAVE)
	{
		// for slave mode
		temCr1 &= ~(1<<2) ;
	}
	// 10 - select communication mode
	switch ( SPIConfig->Communication_Mode)
	{
	case SPI_DIR_2LINE_TXRX :
		temCr1 &=~((1<<15)|(1<<10)) ;
		break ;
	case SPI_DIR_2LINE_RXONLY :
		temCr1 &=~(1<<15) ;
		temCr1 |=(1<<10) ;
		break;
	case SPI_DIR_1LINE_TXONLY :
	case SPI_DIR_1LINE_RXONLY :
		temCr1 |= (SPIConfig->Communication_Mode<<14) ;
		break ;
	}

	// 11- interrupt configuration
	if (SPIConfig->IRQ_EN != SPI_IRQ_NONE)
	{
		temCr2 |= (SPIConfig->IRQ_EN<<5) ;
		if (SPIx==SPI1)
		{
			NVIC_IRQ35_SPI1_EN() ;
		}else if (SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_EN();
		}
	}

	// 12 - enable SPIx
	temCr1 |= (1<<6) ;

	// 13 assign all configuration to registers
	SPIx->CR1 =(uint16_t) temCr1 ;
	SPIx->CR2 =(uint16_t) temCr2 ;

	MCAL_SPI_GPIO_SET_PINS(SPIx) ;
	//end
}


/******************************************************************************
 * \Syntax          : void MCAL_SPI_RST(SPI_REG_t *SPIx)
 * \Description     : reset SPIx module
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : SPI_REG_t *SPIx >> instant of SPI
 * \Return value:   : none
 *******************************************************************************/
void MCAL_SPI_RST(SPI_REG_t *SPIx){

	if (SPIx==SPI1)
	{
		NVIC_IRQ35_SPI1_DIS() ;
		RCC_SPI1_CLK_RST() ;
	}else if (SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_DIS();
		RCC_SPI2_CLK_RST() ;
	}
}

/******************************************************************************
 * \Syntax          : void MCAL_SPI_SendData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism Polling_State);
 * \Description     : Send data
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : SPI_REG_t *SPIx >> instant of SPI
 * \Parameters (in) : uint16_t *ptBuffer >> address of data buffer
 * \Parameters (in) : SPI_Polling_Mechanism Polling_State >> method of check if it interrupt or polling
 * \Return value:   : none
 *******************************************************************************/
void MCAL_SPI_SendData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism Polling_State)
{
	if (Polling_State == SPIPollingEN)
	{
		while (!(SPIx->SR&(1<<1)));

		SPIx->DR = (uint32_t)*ptBuffer ;
	}

}

/******************************************************************************
 * \Syntax          : void MCAL_SPI_ReceiveData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism*Polling_State);
 * \Description     : receive data
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : SPI_REG_t *SPIx >> instant of SPI
 * \Parameters (in) : uint16_t *ptBuffer >> address of data buffer
 * \Parameters (in) : SPI_Polling_Mechanism Polling_State >> method of check if it interrupt or polling
 * \Return value:   : none
 *******************************************************************************/
void MCAL_SPI_ReceiveData(SPI_REG_t *SPIx ,uint16_t *ptBuffer ,SPI_Polling_Mechanism Polling_State)
{
	if (Polling_State == SPIPollingEN)
	{
		while (!(SPIx->SR&(1<<0)));

	}
	*ptBuffer = (uint16_t)SPIx->DR  ;


}
/******************************************************************************
 * \Syntax          : void MCAL_SPI_TXRX(SPI_REG_t *SPIx ,uint16_t *ptTXRXBuffer ,SPI_Polling_Mechanism Polling_State);
 * \Description     : receive and send data
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : SPI_REG_t *SPIx >> instant of SPI
 * \Parameters (in) : uint16_t *ptBuffer >> address of data buffer
 * \Parameters (in) : SPI_Polling_Mechanism Polling_State >> method of check if it interrupt or polling
 * \Return value:   : none
 *******************************************************************************/
void MCAL_SPI_TXRX(SPI_REG_t *SPIx ,uint16_t *ptTXRXBuffer ,SPI_Polling_Mechanism Polling_State)
{
	//send data

	if (Polling_State == SPIPollingEN)
		while (!(SPIx->SR&(1<<1)));
	SPIx->DR = (uint32_t)*ptTXRXBuffer ;
	//receive data
	if (Polling_State == SPIPollingEN)
		while (!(SPIx->SR&(1<<0)));
	*ptTXRXBuffer = (uint16_t)SPIx->DR  ;

}

//


///******************************************************************************
// * \Syntax          : void MCAL_SPI_GPIO_SET_PINS(SPI_REG_t *SPIx)
// * \Description     : configure pins to AFIO recommendation
// * \Sync\Async      : Synchronous
// * \Reentrancy      : Reentrant
// * \Parameters (in) : USART_REG_t* SPIx >> instant of SPI
// * \Return value:   : none
// *******************************************************************************/
void MCAL_SPI_GPIO_SET_PINS(SPI_REG_t *SPIx){

	GPIO_PinConfig_t SPIPIN ;

	if (SPIx==SPI1)
	{
		//		PA4 SPI1_NSS
		//		PA5 SPI1_SCK
		//		PA6 SPI1_MISO
		//		PA7 SPI1_MOSI

		if (Gptr_SPICnfig[SPI1_Index]->Mode == SPI_MODE_MASTER)
		{

			//SPI1_SCK Master
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI1_SCK ;
			MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;

			//SPI1_MOSI Full duplex master or half duplex master
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI1_MOSI ;
			MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;

			//SPI1_NSS hardware master

			if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_HW_OP_DIS )
			{
				// if output disable >>> input to sense multi master
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI1_NSS ;
				MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;

			}else if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_HW_OP_EN ){

				// if output enable  >>> can't use to sense multi master
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
				SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
				SPIPIN.GPIO_PIN =SPI1_NSS ;
				MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;
			}

			//SPI1_MISO in master
			if (Gptr_SPICnfig[SPI1_Index]->Communication_Mode == SPI_DIR_2LINE_TXRX )
			{
				// full duplex
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI1_MISO ;
				MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;
			}
			// to do master half duplex

		}else if (Gptr_SPICnfig[SPI1_Index]->Mode == SPI_MODE_SLAVE)
		{

			//SPI1_SCK Slave
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			SPIPIN.GPIO_PIN =GPIO_PIN5 ;
			MCAL_GPIO_Init(GPIOA,&SPIPIN) ;


			//SPI1_MOSI Full duplex slave
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			SPIPIN.GPIO_PIN =GPIO_PIN7 ;
			MCAL_GPIO_Init(GPIOA,&SPIPIN) ;


			if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_SW_DIS )
			{
				//for hardware NSS slave
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI1_NSS ;
				MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;

			}

			//SPI1_MISO in slave
			// to do multi slave open drain
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED = GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI1_MISO ;
			MCAL_GPIO_Init(SPI1_Port,&SPIPIN) ;


		}



	}else if (SPIx==SPI2)
	{
		if (Gptr_SPICnfig[SPI1_Index]->Mode == SPI_MODE_MASTER)
		{

			//SPI1_SCK Master
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI2_SCK ;
			MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;

			//SPI1_MOSI Full duplex master or half duplex master
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI2_MOSI ;
			MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;

			//SPI1_NSS hardware master

			if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_HW_OP_DIS )
			{
				// if output disable >>> input to sense multi master
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI2_NSS ;
				MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;

			}else if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_HW_OP_EN ){

				// if output enable  >>> can't use to sense multi master
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
				SPIPIN.GPIO_SPEED =GPIO_SPEED_10M ;
				SPIPIN.GPIO_PIN =SPI2_NSS ;
				MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;
			}

			//SPI1_MISO in master
			if (Gptr_SPICnfig[SPI1_Index]->Communication_Mode == SPI_DIR_2LINE_TXRX )
			{
				// full duplex
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI2_MISO ;
				MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;
			}
			// to do master half duplex

		}else if (Gptr_SPICnfig[SPI1_Index]->Mode == SPI_MODE_SLAVE)
		{

			//SPI1_SCK Slave
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			SPIPIN.GPIO_PIN =SPI2_SCK ;
			MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;


			//SPI1_MOSI Full duplex slave
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
			SPIPIN.GPIO_PIN =SPI2_MOSI ;
			MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;


			if ( Gptr_SPICnfig[SPI1_Index]->NSS == SPI_NSS_SW_DIS )
			{
				//for hardware NSS slave
				SPIPIN.GPIO_MODE = GPIO_MODE_ALT_INPUT ;
				SPIPIN.GPIO_PIN =SPI2_NSS ;
				MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;

			}

			//SPI1_MISO in slave
			// to do multi slave open drain
			SPIPIN.GPIO_MODE = GPIO_MODE_ALT_OUTPUT_PP ;
			SPIPIN.GPIO_SPEED = GPIO_SPEED_10M ;
			SPIPIN.GPIO_PIN =SPI2_MISO ;
			MCAL_GPIO_Init(SPI2_Port,&SPIPIN) ;


		}

	}
}


////ISR
//

/**********************************************************************************************************************
 * ISR
 *********************************************************************************************************************/


void SPI1_IRQHandler(){
	SPI_IRQ_SRC_t interrupt_source ;
	interrupt_source.TXE = SPI1->SR>>1;
	interrupt_source.RXNE = SPI1->SR>>0;
	interrupt_source.ERR = SPI1->SR>>4;
	Gptr_SPICnfig[SPI1_Index]->ptr_IRQ_CallBack(interrupt_source);

}
void SPI2_IRQHandler(){
	SPI_IRQ_SRC_t interrupt_source ;
	interrupt_source.TXE = SPI2->SR>>1;
	interrupt_source.RXNE = SPI2->SR>>0;
	interrupt_source.ERR = SPI2->SR>>4;
	Gptr_SPICnfig[SPI2_Index]->ptr_IRQ_CallBack(interrupt_source);

}

/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
