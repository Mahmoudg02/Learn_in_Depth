//
// Created by MAshr on 22/09/2022.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_FIFO_CONFIG_H
#define STUDENT_MANAGEMENT_SYSTEM_FIFO_CONFIG_H

#include "Management_system_types.h"

// USER configuration
//select  element type
//fifo data types
#define element_type studentInfo_t
#define buffSize (unsigned int)50
extern systemStatus_t systemPrintStudent(studentInfo_t *);
extern systemStatus_t (*ptrPrinterFnc)(studentInfo_t*);
#endif //STUDENT_MANAGEMENT_SYSTEM_FIFO_CONFIG_H
