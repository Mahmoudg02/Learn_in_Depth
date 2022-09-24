//
// Created by MAshr on 22/09/2022.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_MANAGEMENT_SYSTEM_TYPES_H
#define STUDENT_MANAGEMENT_SYSTEM_MANAGEMENT_SYSTEM_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef struct {
    int roll ;
    char firstName[20];
    char lastName[20];
    float GPA ;
    int courseID[5];
}studentInfo_t;

typedef enum {
    System_noError,
    System_Error

}systemStatus_t;
#endif //STUDENT_MANAGEMENT_SYSTEM_MANAGEMENT_SYSTEM_TYPES_H
