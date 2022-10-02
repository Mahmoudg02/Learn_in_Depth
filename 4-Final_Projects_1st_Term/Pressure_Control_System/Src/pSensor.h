/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 18:32:02
 * @modify date 2022-09-17 18:32:02
 * @desc [description]
 */

#ifndef pSensor_H_
#define pSensor_H_


/* -------------------------------------------------------------------------- */
/*                               included files                               */
/* -------------------------------------------------------------------------- */
#include "states.h"
#include <stdint.h>
#include "driver.h"
#include "control.h"
/* ------------------------- pressure sensor states ------------------------- */
typedef enum
{
    reading
} pSensorState_t;

/* -------------------------------------------------------------------------- */
/*                              global functions                              */
/* -------------------------------------------------------------------------- */
STATE_define(reading);

/* -------------------------------------------------------------------------- */
/*                                 global vars                                */
/* -------------------------------------------------------------------------- */
 extern void (*ppSensor_state)();

#endif
