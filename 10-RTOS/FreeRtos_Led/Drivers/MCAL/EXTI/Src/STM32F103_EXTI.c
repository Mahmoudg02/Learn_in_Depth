/*
 * STM32F103_EXTI.c
 *
 *  Created on: 30 Oct 2022
 *      Author: MAshr
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STM32F103_EXTI.c
 *       Author:  Mahmoud_Ashraf
 *   	   Date:  30/10/2022
 *       Module:
 *		  Brief:
 *  Description:  STM32F103 EXTI Driver
 *
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STM32F103_EXTI.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*CallBackHandler[16])(void) ;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void NVIC_EXTI_ENABLE(uint32_t LineNumber){

	switch (LineNumber) {
		case 0:
			NVIC_IRQ6_EXTI0_EN() ;
			break;
		case 1 :
			NVIC_IRQ8_EXTI2_EN() ;
			break ;
		case 2 :
			NVIC_IRQ8_EXTI2_EN() ;
			break ;
		case 3 :
			NVIC_IRQ9_EXTI3_EN() ;
			break ;
		case 4 :
			NVIC_IRQ10_EXTI4_EN() ;
			break ;
		case 5 :
		case 6 :
		case 7 :
		case 8 :
		case 9 :
			NVIC_IRQ23_EXTI9_5_EN() ;
			break ;
		case 10 :
		case 11 :
		case 12 :
		case 13 :
		case 14 :
		case 15 :
			NVIC_IRQ40_EXTI15_10_EN() ;
		default:
			break;
	}
}


void NVIC_EXTI_DISABLE(uint32_t LineNumber){

	switch (LineNumber) {
		case 0:
			NVIC_IRQ6_EXTI0_DIS() ;
			break;
		case 1 :
			NVIC_IRQ8_EXTI2_DIS() ;
			break ;
		case 2 :
			NVIC_IRQ8_EXTI2_DIS() ;
			break ;
		case 3 :
			NVIC_IRQ9_EXTI3_DIS() ;
			break ;
		case 4 :
			NVIC_IRQ10_EXTI4_DIS() ;
			break ;
		case 5 :
		case 6 :
		case 7 :
		case 8 :
		case 9 :
			NVIC_IRQ23_EXTI9_5_DIS() ;
			break ;
		case 10 :
		case 11 :
		case 12 :
		case 13 :
		case 14 :
		case 15 :
			NVIC_IRQ40_EXTI15_10_DIS() ;
		default:
			break;
	}
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void MCAL_EXTI_GPIO_Init( EXTI_PinCfg_t* EXTI_Cfg) ;
void MCAL_EXTI_GPIO_Update( EXTI_PinCfg_t* EXTI_Cfg) ;


/******************************************************************************
 * \Syntax          : void MCAL_EXTI_GPIO_Reset( EXTI_PinCfg_t* EXTI_Cfg)
 * \Description     : reset all values of EXTI registers
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) :  void
 * \Return value:   : void
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_EXTI_GPIO_Reset( void) {

	EXTI->IMR =0x00000000 ;
	EXTI->EMR =0x00000000 ;
	EXTI->RTSR =0x00000000 ;
	EXTI->FTSR =0x00000000 ;
	EXTI->SWIER =0x00000000 ;
	EXTI->PR =0xFFFFFFFF ;

	NVIC_IRQ6_EXTI0_DIS();
	NVIC_IRQ7_EXTI1_DIS();
	NVIC_IRQ8_EXTI2_DIS() ;
	NVIC_IRQ9_EXTI3_DIS() ;
	NVIC_IRQ10_EXTI4_DIS() ;
	NVIC_IRQ23_EXTI9_5_DIS() ;
	NVIC_IRQ40_EXTI15_10_DIS() ;
}

/******************************************************************************
 * \Syntax          : void MCAL_EXTI_GPIO_Init( EXTI_PinCfg_t* EXTI_Cfg) ;
 * \Description     : this function shall init the EXTI by the req. configuration
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) :  EXTI_PinCfg_t* EXTI_Cfg  --> configuration structure
 * \Return value:   : void
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_EXTI_GPIO_Init( EXTI_PinCfg_t* EXTI_Cfg){

	//1- config the gpio pin to floating input

	GPIO_PinConfig_t pin ;
	pin.GPIO_PIN = EXTI_Cfg->EXTI_PIN.GPIO_Pin ;
	pin.GPIO_MODE = GPIO_MODE_INPUT_FLOATING ;
	MCAL_GPIO_Init(EXTI_Cfg->EXTI_PIN.GPIO_Port, &pin) ;

	//2- Update AFIO to rout between Ports and EXTI lines
	uint8_t AFIO_EXTICR_index = EXTI_Cfg->EXTI_PIN.EXTI_LineNumber/ 4 ;
	uint8_t AFIO_EXTICR_pos =  (EXTI_Cfg->EXTI_PIN.EXTI_LineNumber % 4)*4 ;
	//clear four bits
	AFIO->EXTICR[AFIO_EXTICR_index]&=~(0xF<<AFIO_EXTICR_pos) ;

	//set_data to EXTICR
	AFIO->EXTICR[AFIO_EXTICR_index]|= (((	(EXTI_Cfg->EXTI_PIN.GPIO_Port==GPIOA)? (0):
			(EXTI_Cfg->EXTI_PIN.GPIO_Port==GPIOB)? (1):
					(EXTI_Cfg->EXTI_PIN.GPIO_Port==GPIOC)? (3):
							(EXTI_Cfg->EXTI_PIN.GPIO_Port==GPIOD)? (4):(8))&0xF)
			<<AFIO_EXTICR_pos);

	//3- set the triggering condition

	EXTI->FTSR &=~( EXTI_Cfg->EXTI_PIN.GPIO_Pin) ;
	EXTI->RTSR &=~( EXTI_Cfg->EXTI_PIN.GPIO_Pin) ;

	switch(EXTI_Cfg->EXTI_Trigger){
	case EXTI_Trigger_Rising :
		EXTI->RTSR |= EXTI_Cfg->EXTI_PIN.GPIO_Pin ;
		break ;
	case EXTI_Trigger_Falling :
		EXTI->FTSR |= EXTI_Cfg->EXTI_PIN.GPIO_Pin ;
		break  ;
	case EXTI_Trigger_Rising_Falling :
		EXTI->FTSR |= EXTI_Cfg->EXTI_PIN.GPIO_Pin ;
		EXTI->RTSR |= EXTI_Cfg->EXTI_PIN.GPIO_Pin ;
		break ;
	}

	// 4 - Update CallBack Handler
	CallBackHandler[EXTI_Cfg->EXTI_PIN.EXTI_LineNumber]= EXTI_Cfg->P_IRQ_CallBack ;

	//5- Enable and disable IRQ
	if(EXTI_Cfg->EXTI_IRQ_EN == EXTI_Enable)
	{
		EXTI->IMR |= (EXTI_Cfg ->EXTI_PIN.GPIO_Pin) ;
		NVIC_EXTI_ENABLE(EXTI_Cfg->EXTI_PIN.EXTI_LineNumber) ;

	}else if (EXTI_Cfg->EXTI_IRQ_EN == EXTI_Disable)
	{
		EXTI->IMR &=~ (EXTI_Cfg ->EXTI_PIN.GPIO_Pin) ;
		NVIC_EXTI_DISABLE(EXTI_Cfg->EXTI_PIN.EXTI_LineNumber) ;

	}
}

/**********************************************************************************************************************
 *  ISR FUNCTIONS
 *********************************************************************************************************************/

void EXTI0_IRQHandler(void ){
	EXTI->PR|=(GPIO_PIN0) ;
	CallBackHandler[0]();
}
void EXTI1_IRQHandler(void ){
	EXTI->PR|=(GPIO_PIN1) ;
	CallBackHandler[1]();
}
void EXTI2_IRQHandler(void ){
	EXTI->PR|=(GPIO_PIN2) ;
	CallBackHandler[2]();
}
void EXTI3_IRQHandler(void ){
	EXTI->PR|=(GPIO_PIN3) ;
	CallBackHandler[3]();
}
void EXTI4_IRQHandler(void ){
	EXTI->PR|=(GPIO_PIN4) ;
	CallBackHandler[4]();
}

void EXTI9_5_IRQHandler(void){

	if (EXTI->PR & 1<<5){ EXTI->PR |= 1<<5  ; 	CallBackHandler[5]() ; }
	if (EXTI->PR & 1<<6){ EXTI->PR |= 1<<6  ; 	CallBackHandler[6]() ; }
	if (EXTI->PR & 1<<7){ EXTI->PR |= 1<<7  ; 	CallBackHandler[7]() ; }
	if (EXTI->PR & 1<<8){ EXTI->PR |= 1<<8  ; 	CallBackHandler[8]() ; }
	if (EXTI->PR & 1<<9){ EXTI->PR |= 1<<9  ; 	CallBackHandler[9]() ; }

}

void EXTI10_15_IRQHandler(void){

	if (EXTI->PR & 1<<10){ EXTI->PR |= 1<<10  ; 	CallBackHandler[10]() ; }
	if (EXTI->PR & 1<<11){ EXTI->PR |= 1<<11  ; 	CallBackHandler[11]() ; }
	if (EXTI->PR & 1<<12){ EXTI->PR |= 1<<12  ; 	CallBackHandler[12]() ; }
	if (EXTI->PR & 1<<13){ EXTI->PR |= 1<<13  ; 	CallBackHandler[13]() ; }
	if (EXTI->PR & 1<<14){ EXTI->PR |= 1<<14  ; 	CallBackHandler[14]() ; }
	if (EXTI->PR & 1<<15){ EXTI->PR |= 1<<15  ; 	CallBackHandler[15]() ; }

}

/**********************************************************************************************************************
 *  END OF FILE: STM32F103_EXTI.c
 *********************************************************************************************************************/
