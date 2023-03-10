/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STM32F103C6_EEPROM.h
 *       Author:  Mahmoud Ashraf
 *         Date:  DEC 30, 2022
 *       Module:
 *        Brief:
 *  Description:  <Hal layer for EEPROM >
 *
 *********************************************************************************************************************/
#ifndef EEPROM_H_
#define EEPROM_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STM32F103_I2C.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
 * EEPROM is an I2C Slave
 *
 * Idle Mode ================> The device is in high-Impedane state and waits for data.
 * Master Transmitter Mode ==> The device transmits data to a slave receiver.
 * Master Receiver Mode =====> The device receives data form a slave transmitter.
 */

#define EEPROM_Slave_Address 		0x2A

/**********************************************************************************************************************
 *  GLOBAL API
 *********************************************************************************************************************/

void HAL_EEPROM_Init(void);

uint8_t HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);
uint8_t HAL_EEPROM_Read_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);



#endif //EEPROM_H_
