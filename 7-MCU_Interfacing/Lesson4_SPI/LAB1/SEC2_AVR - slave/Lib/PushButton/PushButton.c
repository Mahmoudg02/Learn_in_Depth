/*
 * PushButton.c
 *
 * Created: 09/08/2022 01:01:08
 *  Author: MAshr
 */ 

/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/

#include "PushButton.h"
#include "../GPIO/GPIO.h" 



/*----------------------------------------------------------------
--------------------- Private Constants ---------------------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Private Data Types -------------------------
----------------------------------------------------------------*/
typedef struct {
	u8 Push_Button_Port ;
	u8 Push_Button_Pin ;
	u8 Pull_UP_state ;
}Push_Button_Connection;

/*----------------------------------------------------------------
--------------------- Private Variable Definitions ---------------
----------------------------------------------------------------*/


/*----------------------------------------------------------------
--------------------- Public Variable Definitions ----------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Private Functions Prototypes ---------------
----------------------------------------------------------------*/


/*----------------------------------------------------------------
--------------------- Public Function Definitions ----------------
----------------------------------------------------------------*/

Push_Button_Connection Push_Buttons[Number_of_PB] ={
	{Port_D,2,Pull_UP_Disabled},
	{Port_D,1,Pull_UP_Disabled},
	{Port_D,0,Pull_UP_Disabled}
};


u8 Push_Button_Init(void){
	
	for (u8 i=0 ; i<Number_of_PB ; i++)
	{
		GPIO_WritePin_Dir(Push_Buttons[i].Push_Button_Port,Push_Buttons[i].Push_Button_Pin, LOW) ;
		GPIO_WritePin(Push_Buttons[i].Push_Button_Port,Push_Buttons[i].Push_Button_Pin,Push_Buttons[i].Pull_UP_state);
	}
	return No_Error ;
}

u8 Get_Button_state(u8 PB_name){

	if (GPIO_ReadPin(Push_Buttons[PB_name].Push_Button_Port,Push_Buttons[PB_name].Push_Button_Pin)==0)
	{
		return PRESSED ;
	}
	else return RELEASED ;
	
}
/*----------------------------------------------------------------
--------------------- Private Functions Definitions --------------
----------------------------------------------------------------*/

