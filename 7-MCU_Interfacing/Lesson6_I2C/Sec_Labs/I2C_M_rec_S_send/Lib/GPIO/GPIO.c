
#include"GPIO.h"



u8 Get_Port_Addr(u8 port){
	u8 base_address =0 ;
	switch (port){
		
		case Port_A :
		base_address= BASE_PORTA ;
		break ;
		
		case Port_B :
		base_address= BASE_PORTB ;
		break;
		
		case Port_C :
		base_address= BASE_PORTC ;
		break;
		
		case Port_D :
		base_address= BASE_PORTD ;
		break ;
		

	}
	
	return base_address ;
}
/************************************************************************/
/* Initialization of ports                                              */                       
/************************************************************************/
void GPIO_init(void){
for (int i = 0 ;i<Number_of_Ports ;i++)
{
	GPIO_WritePort_DIR(GPIO_PORT_DIR_input,i) ;

}

}
/************************************************************************/
/* Port Operations                                                      */             
/************************************************************************/
// read port direction which is DDRx
u8 GPIO_ReadPort_DIR (u8 PortName){
	return *(volatile u8*)(Get_Port_Addr(PortName)+ DIR_OFFSET);
}

//read port value in input case from PINx
u8 GPIO_ReadPort(u8 PortName){
	return *(volatile u8*)(Get_Port_Addr(PortName)+PIN_OFFSET) ;
}

//set port value in register PORTx
u8 GPIO_WritePort(u8 PortVal , u8 PortName){
	*(volatile u8*)(Get_Port_Addr(PortName)+PORT_OFFSET)=PortVal ;
	return No_Error ;
}

// set port direction in register DDRx
u8 GPIO_WritePort_DIR(u8 PortVal , u8 PortName){
	*(volatile u8*)(Get_Port_Addr(PortName)+ DIR_OFFSET)=PortVal ;
	return No_Error ;
}

/************************************************************************/
/* PINS operation                                                        */            
/************************************************************************/

//read pin from PINx.y
u8 GPIO_ReadPin(u8 PortName,u8 PinIndex){
	return ((*(volatile u8*)(Get_Port_Addr(PortName)+PIN_OFFSET))>>PinIndex)&0x01;
}

//read pin direction from DDRx.y
u8 GPIO_ReadPin_DIR(u8 PortName,u8 PinIndex){
return	((*(volatile u8*)(Get_Port_Addr(PortName)+DIR_OFFSET))>>PinIndex)&0x01;
}

//set pin value when output mode high or low 
u8 GPIO_WritePin(u8 PortName,u8 PinIndex,u8 PinVal){
	u8 API_State ;
	
	//(PinVal>8)?API_State=Error_Occurred:API_State=No_Error ;
	
	switch(PinVal){
		case 1 :
			*(volatile u8*)(Get_Port_Addr(PortName)+PORT_OFFSET)|=(1<<PinIndex);
			API_State=No_Error;
		break;
		case 0 : 
			*(volatile u8*)(Get_Port_Addr(PortName)+PORT_OFFSET)&=~(1<<PinIndex);
			API_State =No_Error ;
		break;
		default:
		API_State=Error_Occurred;
	}
	return API_State ;
}

//set pin direction input or output 
u8 GPIO_WritePin_Dir(u8 PortName,u8 PinIndex,u8 PinVal){
	u8 API_State ;
	
	//(PinVal>8)?API_State=Error_Occurred:API_State=No_Error ;
	
	switch(PinVal){
		case 1 :
		*(volatile u8*)(Get_Port_Addr(PortName)+DIR_OFFSET)|=(1<<PinIndex);
		API_State=No_Error;
		break;
		case 0 :
		*(volatile u8*)(Get_Port_Addr(PortName)+DIR_OFFSET)&=~(1<<PinIndex);
		API_State =No_Error ;
		break;
		default:
		API_State=Error_Occurred;
	}
	return API_State ;
}