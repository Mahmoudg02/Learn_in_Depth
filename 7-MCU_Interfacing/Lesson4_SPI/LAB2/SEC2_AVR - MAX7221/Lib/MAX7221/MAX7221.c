/*
 * MAX7221.c
 *
 * Created: 11/11/2022 22:15:54
 *  Author: MAshr
 */ 
#include "MAX7221.h"

void MAX_7sig_Init(){
	SPI_cnfg_t max7 ;
	max7.IRQ =SPI_IRQ_DIS ;
	max7.Speed = SPI_SPEED_D16 ;
	max7.MODE = SPI_MODE_MASTER ;
	max7.DataOrder =SPI_DataOrder_MTL ;
	max7.DataMode=SPI_DATA_MODE_0 ;
	
	SPI_Init(&max7) ;
	SPI_Send_2Pack(MAX7SIG_DECODE,0xFF) ; // Decode all segments 
	SPI_Send_2Pack(MAX7SIG_SET_SCANLIMIT,7) ; // scan all 0-8 segments 
	SPI_Send_2Pack(MAX7SIG_SET_INTENSITY,0x0F) ; // Maximum intensity
	SPI_Send_2Pack(MAX7SIG_ONOFF,0x01) ; // turn on display

}
void MAX_7sig_excute(u8 sig ,u8 Data) {
	SPI_Send_2Pack(sig,Data);
}
