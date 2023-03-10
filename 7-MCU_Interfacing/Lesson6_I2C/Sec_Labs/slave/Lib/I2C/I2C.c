/*
 * I2C.c
 *
 * Created: 26/11/2022 18:30:04
 *  Author: MAshr
 */ 
#include "I2C.h"


#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7



void MCAL_I2C_Init( I2C_config_t* I2C_config ) {
	
	myTWBR = (u8)(((I2C_config->fcpu/I2C_config->SCL_Clock)-16)/2*I2C_config->prescaller) ;
	
	myTWSR &=~(0b11) ;
	switch (I2C_config->prescaller) {
		case 1 : 
		myTWSR |= 0 ;
		break;
		case 4 : 
		myTWSR |= 1 ;
		break;
		case 16 : 
		myTWSR|= 2 ;
		break ;
		case 64 : 
		myTWSR |= 3 ;
		break;
	}
	
	
}
void MCAL_I2C_Start(void) {
	myTWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN) ;
	while (!(myTWCR & (1<<TWINT)));
	while((myTWSR&(~0b11))!=0x08) ;
	
}
void MCAL_I2C_Send(u8 Data) {
	
	myTWDR = Data ;
	myTWCR = (1<<TWINT)|(1<<TWEN) ;
	while (!(myTWCR & (1<<TWINT)));
	//MCAL_I2C_Wait(0xC0);
}
void MCAL_I2C_Stop (void) {
		myTWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN) ;

}

void MCAL_I2C_Wait(u8 State_code){
	int x  ;
	while((myTWSR&(~0b11))!=State_code){
		x = (myTWSR&(~0b11)) ;
	}
	
}

void MCAL_I2C_SetAdd(u8 address) {

	myTWAR = address ;
}

void MCAL_I2C_Read(u8* Buff ){

#ifdef I2C_Slave_Mode
	myTWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN) ;
	while ((myTWCR&(1<<TWINT))==0) ;
	MCAL_I2C_Wait(0xA8) ;
	//while ((myTWSR&(~0b11))!=0xA8) ;
#endif
//	myTWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN) ;
//	while ((myTWCR&(1<<TWINT))==0) ;
//	*Buff = myTWDR ;

}
