/*
 * KeyPad.h
 *
 * Created: 15/10/2022 22:09:07
 *  Author: MAshr
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32F103_GPIO.h"

#define KEYPAD_PORT GPIOB   //connect keypad to Port D
#define KEYPAD_PORT_DIR 0xF0 //set the first four pins to be input and high pins to be output 

#define R0		GPIO_PIN0
#define R1		GPIO_PIN1
#define R2		GPIO_PIN3
#define R3		GPIO_PIN4
#define C0		GPIO_PIN5
#define C1		GPIO_PIN6
#define C2		GPIO_PIN7
#define C3		GPIO_PIN8


void KeyPad_Init() ;
uint8_t KeyPad_GetChar();


#endif /* KEYPAD_H_ */
