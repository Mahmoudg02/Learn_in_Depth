/*
 * UART.h
 *
 * Created: 05/11/2022 00:47:13
 *  Author: MAshr
 */ 


#ifndef UART_H_
#define UART_H_
#include "../common/HW_Regisrters.h"
#include "../common/Platform_Types.h"
#include "../common/Bit_man.h"
void MCAL_UART_Init() ;
void MCAL_UART_Send(u8 data) ;
u8 MCAL_UART_Recieve() ;
void MCAL_UART_SendString(u8* ptrData) ;
void MCAL_UART_recString(u8* DataBuff) ;
void MCAL_UART_TXIEN() ;
void MCAL_UART_TXIDIS() ;
void MCAL_UART_RXIEN() ;
void MCAL_UART_RXDIS() ;
void MCAL_UART_SendAsync(u8* DataBaff);

#endif /* UART_H_ */