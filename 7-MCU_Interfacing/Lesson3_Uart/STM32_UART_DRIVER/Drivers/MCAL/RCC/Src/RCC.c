
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  RCC.c
 *       Author:  MAshr  
 *   	   Date:  8 Nov 2022
 *       Module:
 *		  Brief:
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Stm32F103_RCC.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
static uint8_t APB_preScalerTable [8]={0,0,0,0,2,4,8,16} ;


//HPRE[3:0]: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
static uint8_t AHB_preScalerTable[16] ={0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9} ;
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
 * \Syntax          : uint32_t MCAL_RCC_GetFreq_PCLK1(void)
 * \Description     : get the frequency of APB1 Bus
 * \Sync\Async      : Synchronous
 * \Reentrancy      :  Reentrant
 * \Parameters (in) : none
 * \Return value:   : freq of bus (uint32_t ) in MHZ .
 *******************************************************************************/
uint32_t MCAL_RCC_GetFreq_PCLK1(void)
{
	return (MCAL_RCC_GetFreq_HCLK() >> APB_preScalerTable[((RCC->CFGR>>8)&0b111)]) ;
}

/******************************************************************************
 * \Syntax          : uint32_t MCAL_RCC_GetFreq_PCLK2(void)
 * \Description     : get the frequency of APB1 Bus
 * \Sync\Async      : Synchronous
 * \Reentrancy      :  Reentrant
 * \Parameters (in) : none
 * \Return value:   : freq of bus (uint32_t ) in MHZ .
 *******************************************************************************/
uint32_t MCAL_RCC_GetFreq_PCLK2(void)
{
	return (MCAL_RCC_GetFreq_HCLK() >> APB_preScalerTable[((RCC->CFGR>>11)&0b111)]) ;
}

/******************************************************************************
 * \Syntax          : uint32_t MCAL_RCC_GetFreq_HCLK(void)
 * \Description     : get the frequency of AHB Bus
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : none
 * \Return value:   : Freq of bus (uint32_t ) in MHZ .
 *******************************************************************************/
uint32_t MCAL_RCC_GetFreq_HCLK(void)
{
	return (MCAL_RCC_GetFreq_SYSCLK() >> AHB_preScalerTable[((RCC->CFGR>>4)&0b1111)]) ;
}

/******************************************************************************
 * \Syntax          : uint32_t MCAL_RCC_GetFreq_SYSCLK(void) ;
 * \Description     : get the frequency of SysCLK
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : none
 * \Return value:   : Freq of bus (uint32_t ) in MHZ .
 *******************************************************************************/
uint32_t MCAL_RCC_GetFreq_SYSCLK(void)
{
	//  Default CLK is internal Oscillator 8MHZ

	switch((RCC->CFGR>>2)&0b11)
	{
	case (0) :
			return HSI_CLK  ; // internal oscillator selected 8 MHZ
			break ;
	case (1) :
			return HSE_CLK ; //External oscillator selected need more configuration by user
			break  ;
	case(2) :
			return PLL_CLK ; // PLL Module selected >> need more configuration
			break ;
	}

	return 11 ; // will never happen just for avoid warnings .
}

/**********************************************************************************************************************
 *  END OF FILE: RCC.c
 *********************************************************************************************************************/
