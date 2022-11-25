/*
 * MAX7221.h
 *
 * Created: 11/11/2022 22:15:35
 *  Author: MAshr
 */ 


#ifndef MAX7221_H_
#define MAX7221_H_
#include "../SPI/SPI.h"


// comands of MAX7221
#define MAX7SIG_DIGIT0				1
#define MAX7SIG_DIGIT1				2
#define MAX7SIG_DIGIT2				3
#define MAX7SIG_DIGIT3				4
#define MAX7SIG_DIGIT4				5
#define MAX7SIG_DIGIT5				6
#define MAX7SIG_DIGIT6				7
#define MAX7SIG_DIGIT7				8
#define MAX7SIG_DECODE				9
#define MAX7SIG_SET_INTENSITY		10		
#define MAX7SIG_SET_SCANLIMIT		11		
#define MAX7SIG_ONOFF				12
#define MAX7SIG_TEST				15


void MAX_7sig_Init() ;
void MAX_7sig_excute(u8 sig ,u8 Data) ;




#endif /* MAX7221_H_ */