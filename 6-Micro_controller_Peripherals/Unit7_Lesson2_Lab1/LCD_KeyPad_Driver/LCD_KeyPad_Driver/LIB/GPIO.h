

#ifndef GPIO_H
#define GPIO_H

#include"GPIO_Types.h"
#include"HW_Regisrters.h"
/**************************************************************************************
 * 
***************************************************************************************/
#define GPIO_PORT_DIR_input 0x00 
#define GPIO_PORT_DIR_output 0xff
#define Number_of_Ports 4
#define PORT_HIGH 0xff
#define PORT_LOW 0x00
#define PORT_OUTPUT 0xff
#define PORT_INPUT 0x00
#define PIN_INPUT 0x00
#define PIN_OUTPUT 0x01
#define GPIO_Init_Dir GPIO_PORT_DIR_output
#define GPIO_Init_OP_Val PORT_HIGH
/**************************************************************************************
Register addresses of all Ports A B C D 
***************************************************************************************/
#define BASE_PORTA 0x39
#define BASE_PORTB 0x36
#define BASE_PORTC 0x33
#define BASE_PORTD 0x30

#define PIN_OFFSET 0x00 
#define DIR_OFFSET 0x01
#define PORT_OFFSET 0x02 

/***************************************************************************************
 *  FUNCTIONS 
 ***************************************************************************************/ 
void GPIO_init(void) ;

u8 Get_Port_Addr(u8 port ) ;

u8 GPIO_ReadPort (u8 PortName);
u8 GPIO_WritePort (u8 PortName,u8 PortVal);
u8 GPIO_WritePort_DIR ( u8 PortName, u8 PortVal);
u8 GPIO_ReadPort_DIR (u8 PortName);


u8 GPIO_ReadPin(u8 PortName,u8 PinIndex);
u8 GPIO_ReadPin_DIR(u8 PortName,u8 PinIndex);
u8 GPIO_WritePin(u8 PortName,u8 PinIndex,u8 PinVal);
u8 GPIO_WritePin_Dir(u8 PortName,u8 PinIndex,u8 PinVal);

#endif
