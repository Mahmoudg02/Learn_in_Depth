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

int data=0 ;
int main(void)
{	

SPI_cnfg_t spi_cnfg ;
spi_cnfg.DataMode = SPI_DATA_MODE_3 ;
spi_cnfg.DataOrder =SPI_DataOrder_LTM ;
spi_cnfg.MODE =SPI_MODE_SLAVE ;
spi_cnfg.IRQ = SPI_IRQ_EN;

SPI_Init(&spi_cnfg) ;
GPIO_WritePort_DIR(PORT_OUTPUT,Port_A);

while(1){
//

//  		while(!(mySPSR&(1<<7)));
// 		data = mySPDR ;
		


	


}
return 0 ;
}

ISR(SPI_STC_vect){
	
		mySPCR &=~( 1<<7) ;
		data = mySPDR ;
		mySPDR = data +'a' ;
 		GPIO_WritePort(data ,Port_A) ;
		mySPCR |= 1<<7 ;


}
