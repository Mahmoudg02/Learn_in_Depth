/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STM32F103C6_Device1.h
 *       Author:  Mahmoud Ashraf
 *         Date:  Oct 15, 2022
 *       Module:
 *        Brief:
 *  Description:  <Hardware Description for STM32F103C6 >
 *  
 *********************************************************************************************************************/
#ifndef STM32F103C6_DEVICE_H_
#define STM32F103C6_DEVICE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdlib.h>
#include <stdint.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FLASH_MEMORY_BASE 			0x08000000UL
#define SYSTEM_MEMORY_BASE 			0x1FFFF000UL
#define SRAM_BASE 					0x20000000UL
#define PERIPHERAL_BASE				0x40000000UL
#define CORTEX_M3_PERIPHERALS		0xE0000000UL

#define NVIC_Base					0xE000E100UL
#define NVIC_ISER0					*(volatile uint32_t *)(NVIC_Base + 0x00)
#define NVIC_ISER1					*(volatile uint32_t *)(NVIC_Base + 0x04)
#define NVIC_ISER2					*(volatile uint32_t *)(NVIC_Base + 0x08)
#define NVIC_ICER0					*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1					*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2					*(volatile uint32_t *)(NVIC_Base + 0x88)

/*---------------------
---PERIPHIRAL BASES---
---------------------*/
#define RCC_BASE					0x40021000UL
//A,B Ports Fully Included in LQFP48
#define GPIOA_BASE					0x40010800UL
#define GPIOB_BASE					0x40010C00UL
//C,D Ports Partially Included in LQFP48
#define GPIOC_BASE					0x40011000UL
#define GPIOD_BASE					0x40011400UL
//E Port not Included in LQFP48
#define GPIOE_BASE					0x40011800UL
//Alternative Function input/output base
#define AFIO_BASE					0x40010000UL
//External interrupt base
#define EXTI_BASE					0x40010400UL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND PREPHERALS STRUCTURES
 *********************************************************************************************************************/
/*---------------------
---GPIO REGISTERS---
---------------------*/
typedef struct {
	volatile uint32_t  CRL;
	volatile uint32_t  CRH;
	volatile uint32_t  IDR ;
	volatile uint32_t  ODR ;
	volatile uint32_t  BSRR ;
	volatile uint32_t  BRR ;
	volatile uint32_t  LCKR ;
}GPIO_REG_t;

/*---------------------
---AFIO REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t  EVCR ;
	volatile uint32_t  MAPR ;
	volatile uint32_t  EXTICR[4];
	volatile uint32_t  RESERVED ;
	volatile uint32_t  MAPRs2 ;

}AFIO_REG_t;

/*---------------------
---RCC REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t CR ;
	volatile uint32_t CFGR ;
	volatile uint32_t CIR ;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR ;
	volatile uint32_t AHBENR ;
	volatile uint32_t APB2ENR ;
	volatile uint32_t APB1ENR ;
	volatile uint32_t BDCR ;
	volatile uint32_t CSR ;

}RCC_REG_t;

/*---------------------
---EXTI REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t IMR ;
	volatile uint32_t EMR ;
	volatile uint32_t RTSR ;
	volatile uint32_t FTSR ;
	volatile uint32_t SWIER ;
	volatile uint32_t PR ;

}EXTI_REG_t;

/*---------------------
---EXTI IRQ---
---------------------*/
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

/**********************************************************************************************************************
 *  GLOBAL POINTERS TO INSTANT FOR PERIPHERALS
 *********************************************************************************************************************/
#define GPIOA				((GPIO_REG_t *)GPIOA_BASE)
#define GPIOB				((GPIO_REG_t *)GPIOB_BASE)
#define GPIOC				((GPIO_REG_t *)GPIOC_BASE)
#define GPIOD				((GPIO_REG_t *)GPIOD_BASE)
#define GPIOE				((GPIO_REG_t *)GPIOE_BASE)

#define EXTI				((EXTI_REG_t *)EXTI_BASE)
#define RCC					((RCC_REG_t *)RCC_BASE)
#define AFIO				((AFIO_REG_t *)AFIO_BASE)



/**********************************************************************************************************************
 *  Clock Enable MACROs
 *********************************************************************************************************************/
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR|=(1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR|=(1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR|=(1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR|=(1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR|=(1<<6))

#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR|=(1<<0))

/**********************************************************************************************************************
 *  NVIC Enable MACROs
 *********************************************************************************************************************/
#define NVIC_IRQ6_EXTI0_EN()		(NVIC_ISER0 |= (1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_EN()		(NVIC_ISER0 |= (1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_EN()		(NVIC_ISER0 |= (1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_EN()		(NVIC_ISER0 |= (1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_EN()		(NVIC_ISER0 |= (1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI9_5_EN()		(NVIC_ISER0 |= (1<<EXTI5_IRQ))
#define NVIC_IRQ40_EXTI15_10_EN()	(NVIC_ISER1 |= (1<<(EXTI10_IRQ%32)))

#define NVIC_IRQ6_EXTI0_DIS()		(NVIC_ICER0 |= (1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_DIS()		(NVIC_ICER0 |= (1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_DIS()		(NVIC_ICER0 |= (1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_DIS()		(NVIC_ICER0 |= (1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_DIS()		(NVIC_ICER0 |= (1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI9_5_DIS()	(NVIC_ICER0 |= (1<<EXTI5_IRQ))
#define NVIC_IRQ40_EXTI15_10_DIS()	(NVIC_ICER1 |= (1<<(EXTI10_IRQ%32)))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* STM32F103C6_DEVICE1_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
