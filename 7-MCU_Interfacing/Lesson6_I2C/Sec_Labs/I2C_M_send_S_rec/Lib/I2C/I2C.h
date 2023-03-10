/*
 * I2C.h
 *
 * Created: 26/11/2022 18:30:23
 *  Author: MAshr
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "../common/HW_Regisrters.h"
#include "../common/Platform_Types.h"
#include "../common/Bit_man.h"

//#define I2C_Master_Mode
#define I2C_Slave_Mode


#define prescaller_1	 0 
#define prescaller_4	 1
#define prescaller_16	 2
#define prescaller_64	 3



typedef struct {
	
	u8 prescaller ;
	u32 SCL_Clock ;
	u32 fcpu ;
}I2C_config_t ;

void MCAL_I2C_Init(I2C_config_t* I2C_config) ;
void MCAL_I2C_Start(void) ;
void MCAL_I2C_Send(u8 Data) ;
void MCAL_I2C_Stop (void) ;
void MCAL_I2C_Wait(u8 State_code) ;

void MCAL_I2C_SetAdd(u8 address) ;
void MCAL_I2C_Read(u8* Buff ) ;

#endif /* I2C_H_ */
