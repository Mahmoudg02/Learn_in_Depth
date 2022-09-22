/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 19:22:21
 * @modify date 2022-09-17 19:22:21
 * @desc [description]
 */
/* ----------------------------- included files ----------------------------- */
#include "control.h"
/* ------------------------------- global vars ------------------------------ */
void (*pcontroller_state)();
/* ------------------------------- local vars ------------------------------- */
Controller_State_t Controller_State_ID ; 
/* ------------------------- definition of functions ------------------------ */
void pressure_action(uint8_t pval)
{
    (pval >= threshold) ? (pcontroller_state = STATE(highPressure)) : (pcontroller_state = STATE(idle));
}

STATE_define(idle)
{
    Controller_State_ID = idle;
    SetAlarm(alarm_OFF);
}

STATE_define(highPressure)
{
    Controller_State_ID = highPressure;
    SetAlarm(alarm_ON);
}