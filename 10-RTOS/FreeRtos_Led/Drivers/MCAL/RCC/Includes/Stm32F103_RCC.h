/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Stm32F103_RCC.h
 *       Author:  MAshr  
 *         Date:  8 Nov 2022
 *       Module:
 *        Brief:
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DRIVERS_MCAL_RCC_INCLUDES_STM32F103_RCC_H_
#define DRIVERS_MCAL_RCC_INCLUDES_STM32F103_RCC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STM32F103C6.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HSI_CLK 8
#define HSE_CLK	16
#define PLL_CLK 16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
uint32_t MCAL_RCC_GetFreq_PCLK1(void) ;
uint32_t MCAL_RCC_GetFreq_PCLK2(void) ;
uint32_t MCAL_RCC_GetFreq_SYSCLK(void) ;
uint32_t MCAL_RCC_GetFreq_HCLK(void) ;


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* DRIVERS_MCAL_RCC_INCLUDES_STM32F103_RCC_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/