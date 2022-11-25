/*
 * GccApplication3.c
 *
 * Created: 05/08/2022 18:27:02
 * Author : MAshr
 */ 

#include "Lib/GPIO/GPIO.h"
#include "Lib/common/Bit_man.h"
#include "Lib/LED_MATRIX/LED_MATRIX.h"
#include "Lib/PushButton/PushButton.h"
#include "Lib/S_seg/S_seg.h"
#include "Lib/LCD/LCD.h"
#include "Lib/UART/UART.h"
#include "Lib/SPI/SPI.h"
#define F_CPU 1000000UL

#include <util/delay.h>


int main(void)
{	

SPI_cnfg_t spi_cnfg ;
spi_cnfg.DataMode = SPI_DATA_MODE_3 ;
spi_cnfg.DataOrder =SPI_DataOrder_MTL ;
spi_cnfg.MODE =SPI_MODE_MASTER ;
spi_cnfg.Speed = SPI_SPEED_D16 ;
spi_cnfg.IRQ = SPI_IRQ_DIS ;

SPI_Init(&spi_cnfg) ;
GPIO_WritePort_DIR(PORT_OUTPUT,Port_A) ;
while(1){
	



for (int i = 0 ;i< 255 ; i++)
{
	GPIO_WritePort(SPI_tranc(i),Port_A) ;
	_delay_ms(500) ;
}

}
return 0 ;
}

