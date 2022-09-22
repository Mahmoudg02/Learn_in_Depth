/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 19:22:28
 * @modify date 2022-09-17 19:22:28
 * @desc [description]
 */
#ifndef _CONTROL_H_
#define _CONTROL_H_
/* ----------------------------- included files ----------------------------- */
#include "config.h"
#include "states.h"
#include "stdint.h"
#include "alarm.h"
/* ------------------------------ system states ----------------------------- */
typedef enum{
    idle ,
    highPressure
}Controller_State_t ;

/* --------------------------- declared functions --------------------------- */
STATE_define(idle);
STATE_define(highPressure) ;
void pressure_action(uint8_t) ;
/* ------------------------------- global vars ------------------------------ */

extern void(*pcontroller_state)();

/* ----------------------------------- end ---------------------------------- */
#endif