
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STM32F103_GPIO.c
 *       Author:  MAshr
 *   	   Date:  Oct 15, 2022
 *       Module:
 *		  Brief:
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STM32F103_GPIO.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

uint16_t Get_CRx_Position(uint16_t pin);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : uint16_t Get_CRx_Position(uint16_t pin )
 * \Description     : Takes Pin number from ref @ GPIO_PINs_DEFINE and return the decimal number
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : pin      value of pin number according to ref @ GPIO_PINs_DEFINE
 * \Return value:   : uint16_t   decimal value of pin number
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
uint16_t Get_CRx_Position(uint16_t pin)
{
	uint8_t pos = 0;
	switch (pin)
	{
	case GPIO_PIN0:
	case GPIO_PIN8:
		pos = 0;
		break;
	case GPIO_PIN1:
	case GPIO_PIN9:
		pos = 1;
		break;
	case GPIO_PIN2:
	case GPIO_PIN10:
		pos = 2;
		break;
	case GPIO_PIN3:
	case GPIO_PIN11:
		pos = 3;
		break;
	case GPIO_PIN4:
	case GPIO_PIN12:
		pos = 4;
		break;
	case GPIO_PIN5:
	case GPIO_PIN13:
		pos = 5;
		break;
	case GPIO_PIN6:
	case GPIO_PIN14:
		pos = 6;
		break;
	case GPIO_PIN7:
	case GPIO_PIN15:
		pos = 7;
		break;

	default:
		break;
	}
	return pos * (4);
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void MCAL_GPIO_Init(GPIO_REG_t* GPIOx , GPIO_PinConfig_t* PinConfig )
 * \Description     : Initialize GPIO Pin According to specified configuration
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PinConfig  Pointer to GPIO_PinConfig_t type which contains PIN Configuration
 * \Return value:   : void
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_GPIO_Init(GPIO_REG_t *GPIOx, GPIO_PinConfig_t *PinConfig)
{

	volatile uint32_t *CRx = (PinConfig->GPIO_PIN <= 7) ? (&GPIOx->CRL) : (&GPIOx->CRH);

	*CRx &= ~(0b1111 << Get_CRx_Position(PinConfig->GPIO_PIN)); // reset all cnfg&mode bits //  (MODE[1:0]=00) (CNFy[1:0]=00)

	if (PinConfig->GPIO_MODE <= GPIO_MODE_INPUT_PD) // check if the pin is in input mode
	{
		switch (PinConfig->GPIO_MODE)
		{
		case GPIO_MODE_ANALOG:
			*CRx &= ~(0b11 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 00: Analog mode
			break;
		case GPIO_MODE_FLOATING_INPUT:
			*CRx |= (0b01 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 01: Floating input (reset state)
			break;
		case GPIO_MODE_INPUT_PU:
			*CRx |= (0b10 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 10: Input with pull-up / pull-down
			GPIOx->ODR |= PinConfig->GPIO_PIN;
			break;
		case GPIO_MODE_INPUT_PD:
			*CRx |= (0b10 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 10: Input with pull-up / pull-down
			GPIOx->ODR &= ~PinConfig->GPIO_PIN;
			break;
		}
	}
	else if (PinConfig->GPIO_MODE > GPIO_MODE_INPUT_PD) // check if the pin is in output mode
	{
		//        switch (PinConfig->GPIO_SPEED)
		//        {
		//        case GPIO_SPEED_10M:
		//            *CRx |= (0b01 << (Get_CRx_Position(PinConfig->GPIO_PIN))); //01: Output mode, max speed 10 MHz
		//            break;
		//        case GPIO_SPEED_2M:
		//            *CRx |= (0b10 << (Get_CRx_Position(PinConfig->GPIO_PIN))); //10: Output mode, max speed 2 MHz.
		//            break;
		//        case GPIO_SPEED_50M:
		//            *CRx |= (0b11 << (Get_CRx_Position(PinConfig->GPIO_PIN))); //11: Output mode, max speed 50 MHz
		//            break;
		//        }
		//
		//        switch (PinConfig->GPIO_MODE)
		//        {
		//        case GPIO_MODE_OUTPUT_PP:
		//            *CRx &= ~(0b11 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 00: General purpose output push-pull
		//            break;
		//        case GPIO_MODE_OUTPUT_OD:
		//            *CRx |= (0b01 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 01: General purpose output Open-drain
		//            break;
		//        case GPIO_MODE_ALT_OUTPUT_PP:
		//            *CRx |= (0b10 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 10: Alternate function output Push-pull
		//            break;
		//        case GPIO_MODE_ALT_OUTPUT_OD:
		//            *CRx |= (0b11 << (Get_CRx_Position(PinConfig->GPIO_PIN) + 2)); // CNFy[1:0]: 11: Alternate function output Open-drain
		//            break;

		uint8_t configVal = 0;
		configVal = (((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_SPEED)) & 0x0F;
		*CRx |= (configVal << (Get_CRx_Position(PinConfig->GPIO_PIN)));

		//        }
	}
}

/******************************************************************************
 * \Syntax          : void MCAL_GPIO_Reset(GPIO_REG_t* GPIOx)
 * \Description     : RESET ALL GPIO PORT REGISTERS
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Return value:   : void
 * \notes 		   : none
 *******************************************************************************/
void MCAL_GPIO_Reset(GPIO_REG_t *GPIOx)
{
	uint8_t rstPin = 0;

	if (GPIOx == GPIOA)
	{
		rstPin = 2;
	}
	else if (GPIOx == GPIOB)
	{
		rstPin = 3;
	}
	else if (GPIOx == GPIOC)
	{
		rstPin = 4;
	}
	else if (GPIOx == GPIOD)
	{
		rstPin = 5;
	}
	else if (GPIOx == GPIOE)
	{
		rstPin = 6;
	}

	RCC->APB2RSTR |= (1 << rstPin);
	RCC->APB2RSTR &=~ (1 << rstPin);
}

/******************************************************************************
 * \Syntax          : uint8_t MCAL_GPIO_ReadPin(GPIO_REG_t* GPIOx , uint16_t PinNum);
 * \Description     : Read Pin Value From GPIO Port
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PinNum  	Pin number according to reference @ GPIO_PINs_DEFINE
 * \Return value:   : uint8_t	according to ref @GPIO_PIN_STATE
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
uint8_t MCAL_GPIO_ReadPin(GPIO_REG_t *GPIOx, uint16_t PinNum)
{
	uint8_t bitStatus ;
	if(GPIOx->IDR & (uint32_t)PinNum)
	{
		bitStatus = GPIO_PIN_HIGH ;
	}else
	{
		bitStatus = GPIO_PIN_LOW;
	}

	return bitStatus ;
}

/******************************************************************************
 * \Syntax          : void MCAL_GPIO_WritePin(GPIO_REG_t* GPIOx , uint16_t PinNum ,uint8_t PinVal)
 * \Description     : Write Pin Value to GPIO Port
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PinNum  	Pin number according to reference @ GPIO_PINs_DEFINE
 * \Parameters (in) : PinVal  	according to ref @GPIO_PIN_STATE
 * \Return value:   : none
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_GPIO_WritePin(GPIO_REG_t *GPIOx, uint16_t PinNum, uint8_t PinVal)
{
	if (PinVal)
	{
		//		BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit

		GPIOx->BSRR=(uint32_t)PinNum ;
	}else
	{
		//		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit

		GPIOx->BRR =(uint32_t)PinNum ;
	}
}
/******************************************************************************
 * \Syntax          : uint16_t MCAL_GPIO_ReadPort(GPIO_REG_t* GPIOx )
 * \Description     : Read Port Value From GPIO
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Return value:   : uint16_t 	value of the port after reading
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
uint16_t MCAL_GPIO_ReadPort(GPIO_REG_t *GPIOx)
{
	uint16_t portVal ;
	portVal = (uint16_t)GPIOx->IDR ;
	return portVal ;
}

/******************************************************************************
 * \Syntax          : void MCAL_GPIO_WritePort(GPIO_REG_t* GPIOx , uint16_t PortVal);
 * \Description     : Write Port Value To GPIO
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PortVal    uint16_t type contains the value of Port to assign it
 * \Return value:   : uint16_t 	value of the port after reading
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_GPIO_WritePort(GPIO_REG_t *GPIOx, uint16_t PortVal)
{
	GPIOx->ODR =(uint32_t)PortVal ;
}
/******************************************************************************
 * \Syntax          : void MCAL_GPIO_TogglePin(GPIO_REG_t* GPIOx , uint16_t PinNum) ;
 * \Description     : Toggle Pin Value From GPIO Port
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PinNum  	Pin number according to reference @ GPIO_PINs_DEFINE
 * \Return value:   : none
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
void MCAL_GPIO_TogglePin(GPIO_REG_t *GPIOx, uint16_t PinNum)
{
	GPIOx->ODR^=(PinNum) ;
}

/******************************************************************************
 * \Syntax          : void MCAL_GPIO_LockPin(GPIO_REG_t* GPIOx , uint16_t PinNum)
 * \Description     : Lock Pin From GPIO Port
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : GPIOx      Pointer to GPIO_REG_t type which contains port Registers
 * \Parameters (in) : PinNum  	Pin number according to reference @ GPIO_PINs_DEFINE
 * \Return value:   : uint8_t	check value if the pin locked successfully or not according to ref @GPIO_PIN_LOCKED_STATE
 * \notes 		   : PORT E not used in this chip
 *******************************************************************************/
uint8_t MCAL_GPIO_LockPin(GPIO_REG_t *GPIOx, uint16_t PinNum)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)

	uint32_t temp = (1<<16) ;
	temp |= PinNum ;

	//	Write 1
	GPIOx->LCKR =temp;
	//	Write 0
	GPIOx->LCKR =PinNum;
	//	Write 1
	GPIOx->LCKR =temp;
	//	Write 0
	temp = GPIOx->LCKR ;
	if (GPIOx->LCKR&(1<<16))
	{
		return GPIO_PIN_LOCKED_OK ;
	}
	return GPIO_PIN_LOCKED_ERROR ;

}
/**********************************************************************************************************************
 *  END OF FILE: STM32F103_GPIO.c
 *********************************************************************************************************************/
