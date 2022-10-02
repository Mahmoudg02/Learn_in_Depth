/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 19:21:44
 * @modify date 2022-09-17 19:21:44
 * @desc [description]
 */
#ifndef _ALARM_H_
#define _ALARM_H_
/* ------------------------------ inluded files ----------------------------- */
#include "driver.h"
#include "states.h"
#include "config.h"

#define ON      1
#define OFF     0
/* ------------------------------ alarm states ------------------------------ */
typedef enum
{
    alarm_ON = 0,
    alarm_OFF = 1
} Alarm_State_t;

/* -------------------------------- functions ------------------------------- */
STATE_define(alarm_ON);
STATE_define(alarm_OFF);
void SetAlarm(uint8_t);

/* ------------------------------- global vars ------------------------------ */
extern void (*pAlarmState)();


/* ----------------------------------- end ---------------------------------- */
#endif
