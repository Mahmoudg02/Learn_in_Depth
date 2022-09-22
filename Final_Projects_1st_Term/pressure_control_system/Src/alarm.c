/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 19:21:39
 * @modify date 2022-09-17 19:21:39
 * @desc [description]
 */
#include "alarm.h"
/* ------------------------------- global vars ------------------------------ */
void (*pAlarmState)();
/* ------------------------------- local vars ------------------------------- */
Alarm_State_t Alarm_State_ID ;
/* -------------------------------- functions ------------------------------- */
void SetAlarm(uint8_t s)
{
    (s == alarm_ON) ? (pAlarmState = STATE(alarm_ON)) : (pAlarmState = STATE(alarm_OFF));
}

STATE_define(alarm_ON)
{
    Alarm_State_ID=alarm_ON;
    Set_Alarm_actuator(alarm_ON);
    Delay(Delay_period) ;
    
}

STATE_define(alarm_OFF)
{
    Alarm_State_ID = alarm_OFF ;
    Set_Alarm_actuator(alarm_OFF) ;

}