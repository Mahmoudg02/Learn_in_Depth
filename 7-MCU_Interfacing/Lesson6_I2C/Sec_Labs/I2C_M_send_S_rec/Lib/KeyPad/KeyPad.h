/*
 * KeyPad.h
 *
 * Created: 15/10/2022 22:09:07
 *  Author: MAshr
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 1000000UL
#include "../GPIO/GPIO.h"
#include <util/delay.h>


#define KEYPAD_PORT Port_D   //connect keypad to Port D
#define KEYPAD_PORT_DIR 0xF0 //set the first four pins to be input and high pins to be output 

#define R0		0
#define R1		1
#define R2		2
#define R3		3
#define C0		4
#define C1		5
#define C2		6
#define C3		7


void KeyPad_Init(void) ;
u8 KeyPad_GetChar(void);


#endif /* KEYPAD_H_ */
