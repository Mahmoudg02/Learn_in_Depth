/*
 * _7_seg.c
 *
 * Created: 09/08/2022 11:57:36
 *  Author: MAshr
 */ 
/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/
#include "S_seg.h"
#include "../GPIO/GPIO.h"
/*----------------------------------------------------------------
--------------------- Private Constants ---------------------------
----------------------------------------------------------------*/
#define s_seg_port Port_A


/*----------------------------------------------------------------
--------------------- Private Data Types -------------------------
----------------------------------------------------------------*/
typedef struct{
	u8 port ;
	u8 pin ;
}s_seg_connection;

/*----------------------------------------------------------------
--------------------- Private Variable Definitions ---------------
----------------------------------------------------------------*/
s_seg_connection segment1_connection[4]={
	{Port_C , 4},
	{Port_C , 5},
	{Port_C , 6},
	{Port_C , 7}
};

s_seg_connection segment1_enable[1]={{Port_C , 2}};
/*----------------------------------------------------------------
--------------------- Public Variable Definitions ----------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Private Functions Prototypes ---------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Function Definitions ----------------
----------------------------------------------------------------*/
u8 s_seg_init(void){
	
	GPIO_WritePin_Dir(segment1_enable[0].port,segment1_enable[0].pin,PIN_OUTPUT );
	GPIO_WritePin(segment1_enable[0].port,segment1_enable[0].pin,LOW );
	
	for (u8 i =0 ;i<4 ; i++)
	{
		GPIO_WritePin_Dir(segment1_connection[i].port,segment1_connection[i].pin,PIN_OUTPUT) ;
		GPIO_WritePin(segment1_connection[i].port,segment1_connection[i].pin,LOW) ;
	}
	return No_Error;
}

u8 s_seg_write(u8 number){
	if (number>9)
	return Error_Occurred;
	
	s_seg_enable();
	
	for (u8 i =0 ;i<4 ;i++)
	{
		GPIO_WritePin(segment1_connection[i].port,segment1_connection[i].pin,(number>>i)&0x01) ;
	}
	
	return No_Error ;
}
/*----------------------------------------------------------------
--------------------- Private Functions Definitions --------------
----------------------------------------------------------------*/
u8 s_seg_enable(void){
	
	GPIO_WritePin(segment1_enable[0].port,segment1_enable[0].pin,HIGH );
	return No_Error ;
}

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/