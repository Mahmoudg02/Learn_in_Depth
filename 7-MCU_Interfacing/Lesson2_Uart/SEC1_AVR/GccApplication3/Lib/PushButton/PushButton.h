/*
 * PushButton.h
 *
 * Created: 09/08/2022 01:00:18
 *  Author: MAshr
 */ 

/*----------------------------------------------------------------
--------------------- Header Guard -------------------------------
----------------------------------------------------------------*/

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/
#include "../common/Platform_Types.h"
#include "PushButton_config1.h"


/*----------------------------------------------------------------
--------------------- Public Constants ---------------------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Data Types --------------------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Variable Declarations ---------------
----------------------------------------------------------------*/

/*----------------------------------------------------------------
--------------------- Public Function Prototypes ----------------
----------------------------------------------------------------*/

u8 Push_Button_Init(void);
u8 Get_Button_state(u8 PB_name);

#endif /* PUSHBUTTON_H_ */

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/