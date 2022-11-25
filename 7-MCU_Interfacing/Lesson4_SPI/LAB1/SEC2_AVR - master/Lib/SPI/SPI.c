/*
 * SPI.c
 *
 * Created: 11/11/2022 14:19:10
 *  Author: MAshr
 */ 
#include "SPI.h"
#include <avr/interrupt.h>

void SPI_Init(SPI_cnfg_t* cnfg)
{
	

	// set data mode 
	mySPCR &=~(0b11<<2) ;
	mySPCR |= (cnfg->DataMode)<<2 ;
	// set SPI Mode 
	mySPCR &=~(0b1<<4) ;
	mySPCR |= (cnfg->MODE<<4) ;
	if(cnfg->MODE==SPI_MODE_SLAVE)
	{
		GPIO_WritePin_Dir(SPI_PORT,SPI_SS,PIN_INPUT) ;
		GPIO_WritePin_Dir(SPI_PORT,SPI_MOSI,PIN_INPUT);
		GPIO_WritePin_Dir(SPI_PORT,SPI_MISO,PIN_OUTPUT);
		GPIO_WritePin_Dir(SPI_PORT,SPI_SCK,PIN_INPUT);


		
	}else if (cnfg->MODE==SPI_MODE_MASTER)
	{
		GPIO_WritePin_Dir(SPI_PORT,SPI_SS,PIN_OUTPUT) ;
		GPIO_WritePin_Dir(SPI_PORT,SPI_MOSI,PIN_OUTPUT);
		GPIO_WritePin_Dir(SPI_PORT,SPI_MISO,PIN_INPUT);
		GPIO_WritePin_Dir(SPI_PORT,SPI_SCK,PIN_OUTPUT);
		
		GPIO_WritePin(SPI_PORT,SPI_SS,HIGH) ;
		
	}
	
	// set freq 
	mySPCR &=~(0b11<<0);
	mySPCR|=(cnfg->Speed&0b11)<<0 ;
	if (cnfg->Speed>3)
	{
		mySPSR |= (1<<0 );
	}
	
// 	enable the interrupt 
if (cnfg->IRQ==SPI_IRQ_EN){
	mySPCR |= 1<<7 ;
	sei();
}

//enable SPI 
	mySPCR |= 1<<6 ;

}

u8 SPI_tranc(u8 dataBuff)
{
	GPIO_WritePin(SPI_PORT,SPI_SS,LOW) ;
	mySPDR = dataBuff ;
	while(!(mySPSR&(1<<7))) ;
	GPIO_WritePin(SPI_PORT,SPI_SS,HIGH) ;
	return mySPDR ;
}

ISR(SPI_STC_vect){
static int i =0 ;
mySPDR = 	i ;
i++ ;
if (i>255) i=0 ;
}
