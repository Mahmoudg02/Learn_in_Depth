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
---PERIPHIRAL BASES APB2---
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
//UART1 module base
#define USART1_BASE					0x40013800UL
//SPI1 module base
#define SPI1_BASE					0x40013000UL

/*---------------------
---PERIPHIRAL BASES APB1---
---------------------*/
//UART2 module base
#define USART2_BASE					0x40004800UL
//UART3 module base
#define USART3_BASE					0x40004400UL
//SPI1 module base
#define SPI2_BASE					0x40003800UL
//I2C1  module base
#define I2C1_BASE					(0x40005400UL)
//I2C2  module base
#define I2C2_BASE					(0x40005800UL)


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
---UART REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t SR ;
	volatile uint32_t DR ;
	volatile uint32_t BRR ;
	volatile uint32_t CR1 ;
	volatile uint32_t CR2 ;
	volatile uint32_t CR3 ;
	volatile uint32_t GTBR ;

}USART_REG_t;

/*---------------------
---SPI REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t CR1 ;
	volatile uint32_t CR2 ;
	volatile uint32_t SR ;
	volatile uint32_t DR ;
	volatile uint32_t CRCPR ;
	volatile uint32_t RXCRCR ;
	volatile uint32_t TXCRCR ;
	volatile uint32_t I2SCFGR ;
	volatile uint32_t I2SPR ;
}SPI_REG_t;

/*---------------------
---I2C REGISTERS---
---------------------*/
typedef struct {

	volatile uint32_t CR1 ;
	volatile uint32_t CR2 ;
	volatile uint32_t OAR1 ;
	volatile uint32_t OAR2 ;
	volatile uint32_t DR ;
	volatile uint32_t SR1 ;
	volatile uint32_t SR2 ;
	volatile uint32_t CCR ;
	volatile uint32_t TRISE ;
}I2C_REG_t;

/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/

/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */

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

#define I2C1_EV_IRQ			31
#define I2C1_ER_IRQ			32
#define I2C2_EV_IRQ			33
#define I2C2_ER_IRQ			34

#define SPI1_IRQ			35
#define SPI2_IRQ			36

#define USART1_IRQ			37
#define USART2_IRQ			38
#define USART3_IRQ			39


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

#define USART1				((USART_REG_t *)USART1_BASE)
#define USART2				((USART_REG_t *)USART2_BASE)
#define USART3				((USART_REG_t *)USART3_BASE)

#define SPI1				((SPI_REG_t *)SPI1_BASE)
#define SPI2				((SPI_REG_t *)SPI2_BASE)

#define I2C1				((I2C_REG_t *)I2C1_BASE)
#define I2C2				((I2C_REG_t *)I2C2_BASE)


/**********************************************************************************************************************
 *  Clock Enable MACROs
 *********************************************************************************************************************/
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR|=(1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR|=(1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR|=(1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR|=(1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR|=(1<<6))

//AFIO CLK Enable and Reset
#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR|=(1<<0))
#define RCC_AFIO_CLK_RST()		(RCC->APB2RSTR|=(1<<0))

//SPI CLK Enable and Reset
#define RCC_SPI1_CLK_EN()		(RCC->APB2ENR|=(1<<12))
#define RCC_SPI2_CLK_EN()		(RCC->APB1ENR|=(1<<14))

#define RCC_SPI1_CLK_RST()		(RCC->APB2RSTR|=(1<<12))
#define RCC_SPI2_CLK_RST()		(RCC->APB1RSTR|=(1<<14))

//USART CLK Enable and Reset
#define RCC_USART1_CLK_EN()			(RCC->APB2ENR|=(1<<14))
#define RCC_USART2_CLK_EN()			(RCC->APB1ENR|=(1<<17))
#define RCC_USART3_CLK_EN()			(RCC->APB1ENR|=(1<<18))

#define RCC_USART1_CLK_RST()		(RCC->APB2RSTR|=(1<<14))
#define RCC_USART2_CLK_RST()		(RCC->APB1RSTR|=(1<<17))
#define RCC_USART3_CLK_RST()		(RCC->APB1RSTR|=(1<<18))

// I2C CLK Enable and Reset
#define RCC_I2C1_CLK_EN()			(RCC->APB1ENR|=(1<<21))
#define RCC_I2C2_CLK_EN()			(RCC->APB1ENR|=(1<<22))

#define RCC_I2C1_CLK_RST()			(RCC->APB1RSTR|=(1<<21))
#define RCC_I2C2_CLK_RST()			(RCC->APB1RSTR|=(1<<22))

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

// Enable and disable macros for USART modules
#define NVIC_IRQ37_USART1_EN()		(NVIC_ISER1 |= (1<<(USART1_IRQ%32)))
#define NVIC_IRQ38_USART2_EN()		(NVIC_ISER1 |= (1<<(USART2_IRQ%32)))
#define NVIC_IRQ39_USART3_EN()		(NVIC_ISER1 |= (1<<(USART3_IRQ%32)))

#define NVIC_IRQ37_USART1_DIS()		(NVIC_ICER1 |= (1<<(USART1_IRQ%32)))
#define NVIC_IRQ38_USART2_DIS()		(NVIC_ICER1 |= (1<<(USART2_IRQ%32)))
#define NVIC_IRQ39_USART3_DIS()		(NVIC_ICER1 |= (1<<(USART3_IRQ%32)))

// Enable and disable macros for SPI modules
#define NVIC_IRQ35_SPI1_EN()		(NVIC_ISER1 |= (1<<(SPI1_IRQ%32)))
#define NVIC_IRQ35_SPI1_DIS()		(NVIC_ICER1 |= (1<<(SPI1_IRQ%32)))

#define NVIC_IRQ36_SPI2_EN()		(NVIC_ISER1 |= (1<<(SPI2_IRQ%32)))
#define NVIC_IRQ36_SPI2_DIS()		(NVIC_ICER1 |= (1<<(SPI2_IRQ%32)))


// Enable and disable macros for I2C modules
#define NVIC_IRQ31_I2C1_EV_EN()		(NVIC_ISER0 |= (1<<(I2C1_EV_IRQ%32)))
#define NVIC_IRQ31_I2C1_EV_DIS()	(NVIC_ICER0 |= (1<<(I2C1_EV_IRQ%32)))
#define NVIC_IRQ32_I2C1_ER_EN()		(NVIC_ISER1 |= (1<<(I2C1_ER_IRQ%32)))
#define NVIC_IRQ32_I2C1_ER_DIS()	(NVIC_ICER1 |= (1<<(I2C1_ER_IRQ%32)))


#define NVIC_IRQ33_I2C2_EV_EN()		(NVIC_ISER1 |= (1<<(I2C2_EV_IRQ%32)))
#define NVIC_IRQ33_I2C2_EV_DIS()	(NVIC_ICER1 |= (1<<(I2C2_EV_IRQ%32)))
#define NVIC_IRQ34_I2C2_ER_EN()		(NVIC_ISER1 |= (1<<(I2C2_ER_IRQ%32)))
#define NVIC_IRQ34_I2C2_ER_DIS()	(NVIC_ICER1 |= (1<<(I2C2_ER_IRQ%32)))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* STM32F103C6_DEVICE1_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
