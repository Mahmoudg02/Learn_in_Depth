/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STM32F103_GPIO.h
 *       Author:  MAshr  
 *         Date:  Oct 15, 2022
 *       Module:
 *        Brief:
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DRIVERS_MCAL_INCLUDES_STM32F103_GPIO_H_
#define DRIVERS_MCAL_INCLUDES_STM32F103_GPIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STM32F103C6.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*---------------------
---@ GPIO_PINs_DEFINE---
---------------------*/

#define GPIO_PIN0 			((uint16_t)0x0001) //Pin 0 selected
#define GPIO_PIN1 			((uint16_t)0x0002) //Pin 1 selected
#define GPIO_PIN2 			((uint16_t)0x0004) //Pin 2 selected
#define GPIO_PIN3 			((uint16_t)0x0008) //Pin 3 selected
#define GPIO_PIN4 			((uint16_t)0x0010) //Pin 4 selected
#define GPIO_PIN5 			((uint16_t)0x0020) //Pin 5 selected
#define GPIO_PIN6 			((uint16_t)0x0040) //Pin 6 selected
#define GPIO_PIN7 			((uint16_t)0x0080) //Pin 7 selected
#define GPIO_PIN8 			((uint16_t)0x0100) //Pin 8 selected
#define GPIO_PIN9 			((uint16_t)0x0200) //Pin 9 selected
#define GPIO_PIN10 			((uint16_t)0x0400) //Pin 10 selected
#define GPIO_PIN11 			((uint16_t)0x0800) //Pin 11 selected
#define GPIO_PIN12 			((uint16_t)0x1000) //Pin 12 selected
#define GPIO_PIN13 			((uint16_t)0x2000) //Pin 13 selected
#define GPIO_PIN14 			((uint16_t)0x4000) //Pin 14 selected
#define GPIO_PIN15 			((uint16_t)0x8000) //Pin 15 selected

/*---------------------
---@ GPIO_PINs_MODE---
---------------------*/
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input

#define GPIO_MODE_ANALOG 				((uint8_t)0x00) //0: Analog mode
#define GPIO_MODE_FLOATING_INPUT 		((uint8_t)0x01) //1: Floating input (reset state)
#define GPIO_MODE_INPUT_PU				((uint8_t)0x02)	//2: Input with pull-up
#define GPIO_MODE_INPUT_PD				((uint8_t)0x03) //3: Input with pull-down
#define GPIO_MODE_OUTPUT_PP				((uint8_t)0x04) //4: General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				((uint8_t)0x05) //5: General purpose output Open-drain
#define GPIO_MODE_ALT_OUTPUT_PP			((uint8_t)0x06) //6: Alternate function output Push-pull
#define GPIO_MODE_ALT_OUTPUT_OD			((uint8_t)0x07) //7: Alternate function output Open-drain
#define GPIO_MODE_ALT_INPUT				((uint8_t)0x01) //8: Alternate function input

/*---------------------
---@ GPIO_PINs_SPEED---
---------------------*/
//Refer to Table 20: Port bit configuration table.
//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//02: Output mode, max speed 2 MHz.
//03: Output mode, max speed 50 MHz.

#define GPIO_SPEED_10M					((uint8_t)0x01) //01: Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M					((uint8_t)0x02) //02: Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M					((uint8_t)0x03) //03: Output mode, max speed 50 MHz.


/*---------------------
---@ @GPIO_PIN_STATE---
---------------------*/
#define GPIO_PIN_HIGH 		1		//PIN is SET
#define GPIO_PIN_LOW 		0		//PIN is RESET

/*--------------------------
---@GPIO_PIN_LOCKED_STATE---
---------------------------*/
#define GPIO_PIN_LOCKED_OK 		1		//PIN is SET
#define GPIO_PIN_LOCKED_ERROR  	0		//PIN is RESET

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*---------------------
---PIN CONFIGRATION---
---------------------*/
typedef struct
{	GPIO_REG_t* GPIO_PORT ; //Specifies GPIO Port instant .
	uint16_t GPIO_PIN ;  //Specifies GPIO PIN number to configured according to ref @ GPIO_PINs_DEFINE
	uint8_t GPIO_MODE ;  //Specifies GPIO PIN MODE to configured according to ref   @ GPIO_PINs_MODE
	uint8_t GPIO_SPEED ; //Specifies GPIO PIN SPEED to configured according to ref @ GPIO_PINs_SPEED

}GPIO_PinConfig_t;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES API's
 *********************************************************************************************************************/
void MCAL_GPIO_Init(GPIO_REG_t* GPIOx , GPIO_PinConfig_t* PinConfig );
void MCAL_GPIO_Reset(GPIO_REG_t* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_REG_t* GPIOx , uint16_t PinNum);
void MCAL_GPIO_WritePin(GPIO_REG_t* GPIOx , uint16_t PinNum ,uint8_t PinVal);

uint16_t MCAL_GPIO_ReadPort(GPIO_REG_t* GPIOx );
void MCAL_GPIO_WritePort(GPIO_REG_t* GPIOx , uint16_t PortVal);

void MCAL_GPIO_TogglePin(GPIO_REG_t* GPIOx , uint16_t PinNum) ;
uint8_t MCAL_GPIO_LockPin(GPIO_REG_t* GPIOx , uint16_t PinNum);

#endif  /* DRIVERS_MCAL_INCLUDES_STM32F103_GPIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
