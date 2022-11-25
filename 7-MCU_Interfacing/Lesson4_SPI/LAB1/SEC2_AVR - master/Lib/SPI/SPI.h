/*
 * SPI.h
 *
 * Created: 11/11/2022 14:19:33
 *  Author: MAshr
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../common/Platform_Types.h"
#include "../common/HW_Regisrters.h"
#include "../common/Bit_man.h"
#include "../GPIO/GPIO.h"
#define SPI_PORT			Port_B

#define SPI_SS				4 
#define SPI_MOSI			5
#define SPI_MISO			6
#define SPI_SCK				7


//SPI MODE
#define SPI_MODE_MASTER		1
#define SPI_MODE_SLAVE		0

//SPI_DataOrder
#define SPI_DataOrder_MTL	0
#define SPI_DataOrder_LTM	0

//SPI SPEED
#define SPI_SPEED_D4		0
#define SPI_SPEED_D16		1
#define SPI_SPEED_D64		2
#define SPI_SPEED_D128		3
#define SPI_SPEED_D2		4
#define SPI_SPEED_D8		5
#define SPI_SPEED_D32		6

// SPI Mode Conditions Leading Edge Trailing Edge
// 0 CPOL=0, CPHA=0 Sample (Rising) Setup (Falling)
// 1 CPOL=0, CPHA=1 Setup (Rising) Sample (Falling)
// 2 CPOL=1, CPHA=0 Sample (Falling) Setup (Rising)
// 3 CPOL=1, CPHA=1 Setup (Falling) Sample (Rising)
#define SPI_DATA_MODE_0		0
#define SPI_DATA_MODE_1		1
#define SPI_DATA_MODE_2		2
#define SPI_DATA_MODE_3		3
		
#define SPI_IRQ_DIS			0
#define SPI_IRQ_EN			1

typedef struct
{
	u8 MODE ;			//select SPI mode which is slave or master 
	u8 DataOrder ;		// select data order if it is from least to most or most to least 
	u8 DataMode ;		// set data mode of orientation and polarity of clk 
	u8 Speed ;
	u8 IRQ ;
	
	}SPI_cnfg_t;			

void SPI_Init(SPI_cnfg_t *confg ) ;
u8 SPI_tranc(u8 dataBuff) ;
void SPI_Recieve(u8 *dataBuff) ;



#endif /* SPI_H_ */