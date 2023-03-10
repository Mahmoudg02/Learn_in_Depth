/*
 * ADC.h
 *
 *  Created on: 4 Jan 2023
 *      Author: MAshr
 */

#ifndef ADC_H_
#define ADC_H_


#include <stdint.h>
#include <avr/io.h>
typedef enum {
	ADC_ch0 ,
	ADC_ch1 ,
	ADC_ch2 ,
	ADC_ch3 ,
	ADC_ch4 ,
	ADC_ch5 ,
	ADC_ch6 ,
	ADC_ch7
}ADC_channel;

typedef enum {
single ,
free_run
}ADC_Mode;

typedef enum {
Right  ,
left
}ADC_Data_Adj;

typedef enum {
off  ,
on
}ADC_Interrupt;

typedef enum {
prescaler_2 = 1 ,
prescaler_4 ,
prescaler_8 ,
prescaler_16 ,
prescaler_32 ,
prescaler_64 ,
prescaler_128 ,
}ADC_Prescaler;

typedef enum {
external = 1  ,
internal = 3
}ADC_Ref;

typedef struct {

	ADC_channel CH ;
	ADC_Mode mode ;
	ADC_Data_Adj data_adj ;
	ADC_Interrupt interrupt  ;
	ADC_Prescaler prescaler ;
	ADC_Ref ref ;


}ADC_config;


void MCAL_ADC_Init(ADC_config * config) ;
uint16_t MCAL_ADC_GetRead(void) ;

#endif /* ADC_H_ */
