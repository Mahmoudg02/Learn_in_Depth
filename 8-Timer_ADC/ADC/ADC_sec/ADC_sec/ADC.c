/*
 * ADC.c
 *
 *  Created on: 4 Jan 2023
 *      Author: MAshr
 */

#include "ADC.h"

void MCAL_ADC_Init(ADC_config * config) {
	ADCSRA |= (1<<ADEN) ; // Enable ADC

	ADCSRA |= config->prescaler ; // set pre_scaler

	DDRA &= ~(1<<config->CH) ; //set channel as input

	ADCSRA |= ( config->interrupt << ADIE) ;
	ADCSRA |= ( config->mode << ADATE) ;
	ADMUX|=(config->data_adj << ADLAR) ;
	ADMUX|= ((config->ref)<<REFS0) ;
	ADMUX|= config->CH ;

}


uint16_t MCAL_ADC_GetRead(void) {
	ADCSRA|= ( 1 << ADSC) ;

	while (!(ADCSRA&(1<<ADIF))) ;

	return ADC ;

}
