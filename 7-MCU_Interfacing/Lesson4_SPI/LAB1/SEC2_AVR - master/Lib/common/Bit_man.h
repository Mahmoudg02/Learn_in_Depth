/*
 * Bit_man.h
 *
 * Created: 06/08/2022 19:38:54
 *  Author: MAshr
 */ 

#ifndef BIT_MAN_H_
#define BIT_MAN_H_

#include "Platform_Types.h"


#define SET_BIT(REG,BIT)									(REG) |= ((u8)1<<(BIT))
#define CLR_BIT(REG,BIT)									(REG) &= ~((u8)1<<(BIT))
#define TOGGLE_BIT(REG,BIT)									(REG) ^= ((u8)1<<(BIT))
#define GET_BIT(REG,BIT)									(((REG)>>(BIT))&(u8)0x01)
#define GRT_REG(REG_ADDR,REG_SIZE)							(*(volatile REG_SIZE*)(REG_ADDR))



#endif /* BIT_MAN_H_ */