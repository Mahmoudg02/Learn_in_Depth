/*
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 19:06:55
 * @modify date 2022-09-17 19:06:55
 * @desc [description]
 */

/* ---------------------------- included headers ---------------------------- */
#include "pSensor.h"

/* ------------------------------- local vars ------------------------------- */
uint8_t pressure_val ;
pSensorState_t pSensorState_ID;
/* ------------------------------- global vars ------------------------------ */
void (*ppSensor_state)();
/* -------------------------- functions definition -------------------------- */
STATE_define(reading)
{
    pSensorState_ID = reading; // set the state to reading state
    pressure_val = getPressureVal();
    pressure_action(pressure_val) ;
    ppSensor_state = STATE(reading);
}