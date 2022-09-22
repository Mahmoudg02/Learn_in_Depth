/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 21:34:07
 * @modify date 2022-09-17 21:34:07
 * @desc [description]
 */

#include <stdint.h>
#include "main.h"

void setup_system(void)
{
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(alarm_OFF);
	ppSensor_state = STATE(reading);
	pAlarmState = STATE(alarm_OFF);
	pcontroller_state = STATE(idle);
}

int main()
{
	setup_system();
	
	while (1)
	{
		ppSensor_state();
		pcontroller_state();
		pAlarmState();
	}

	return 0;
}
