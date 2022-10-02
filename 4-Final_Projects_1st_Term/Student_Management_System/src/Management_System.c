//
// Created by MAshr on 23/09/2022.
//
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Management_System.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
studentInfo_t mainBuff[buffSize];
FIFO_buf_t FIFO_info;

systemStatus_t (*ptrPrinterFnc)(studentInfo_t *);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
studentInfo_t *systemCatchStudentData();

systemStatus_t checkRollID(int rollID);

systemStatus_t systemPrintStudent(studentInfo_t *);

systemStatus_t printUpdateMenu();

systemStatus_t updateStudentRoll(studentInfo_t *Student);

systemStatus_t updateStudentFname(studentInfo_t *Student);

systemStatus_t updateStudentLname(studentInfo_t *Student);

systemStatus_t updateStudentGPA(studentInfo_t *Student);

systemStatus_t updateStudentCourses(studentInfo_t *Student);

systemStatus_t FIFO_print_file(FIFO_buf_t *fifo);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

studentInfo_t *systemCatchStudentData() {
    static studentInfo_t temp;
    char str[20];
    Dprintf("Enter Student Roll ID\n");
    scanf("%d", &temp.roll);
    if (!checkRollID(temp.roll)) {
        Dprintf("Enter Student first Name \n");
        gets(str);
        strcpy(temp.firstName, str);
        Dprintf("Enter Student last Name \n");
        gets(str);
        strcpy(temp.lastName, str);
        Dprintf("Enter Student GPA \n");
        scanf("%f", &temp.GPA);
        Dprintf("Enter Student Courses ID\n");
        for (int i = 0; i < 5; i++) {
            Dprintf("==> Enter Course %d ID \n", i + 1);
            scanf("%d", &temp.courseID[i]);
        }
    } else {
        return NULL;
    }
    return &temp;
}

/*----------------------------------------------------------------------------------*/
systemStatus_t printUpdateMenu() {
    Dprintf("Choose which item to update : \n");
    Dprintf("1- Roll ID \n");
    Dprintf("2- First name \n");
    Dprintf("3- Last name \n");
    Dprintf("4- GPA \n");
    Dprintf("5- Courses \n");
    Dprintf("6- Back to main menu\n");
}

systemStatus_t systemPrintMenu() {
    char menu[15][50] = {
            "------------------------------------------\n",
            " Chose the task that you want to perform \n",
            "1- Add the students data manually\n",
            "2- Load Students data from file \n",
            "3- Find student details by roll number \n",
            "4- Find student details by first name  \n",
            "5- Find student details by course ID \n",
            "6- Find total number of students\n",
            "7- Delete student details by roll number \n",
            "8- Update student details by roll number \n",
            "9- Show all information\n",
            "10- Save data to output file\n",
            "11- Exit the system\n",
            "===> Enter your choice number \n "
    };
    for (int i = 0; i < 15; i++) {
        Dprintf("%s", menu[i]);
    }

    return System_noError;
}

/*-------------------------------------------------------------------------------------*/
systemStatus_t checkRollID(int rollID) {
    int i = 0;
    while (i < FIFO_info.count) {
        if (FIFO_info.tail[i].roll == rollID) {
            Dprintf("---------------------------------------------\n");
            Dprintf("[ERROR] : This Roll ID (%d) already exist \n", rollID);
            Dprintf("---------------------------------------------\n");

            systemPrintStudent(&FIFO_info.tail[i]);
            return System_Error;
        }
        i++;
    }

    return System_noError;
}

/*--------------------------------------------------------------------------------------*/
systemStatus_t systemPrintStudent(studentInfo_t *student) {
    Dprintf("Student Roll Number : %d\n", student->roll);
    Dprintf("First Name : %s\n", student->firstName);
    Dprintf("Last Name : %s\n", student->lastName);
    Dprintf("GPA: %f\n", student->GPA);
    Dprintf("Registered Courses ID : [");
    for (int i = 0; i < 5; i++) {
        Dprintf("  %d  ", student->courseID[i]);
    }
    Dprintf("]\n-----------------------------------------\n");
    return System_noError;
}

systemStatus_t updateStudentRoll(studentInfo_t *Student) {
    int nRollID;
    Dprintf("Enter Student (New) Roll ID \n");
    scanf("%d", &nRollID);
    if (!checkRollID(nRollID)) {
        Student->roll = nRollID;
    }
}

systemStatus_t updateStudentFname(studentInfo_t *Student) {
    char str[20];
    Dprintf("Enter Student ( New ) first Name \n");
    gets(str);
    strcpy(Student->firstName, str);
}

systemStatus_t updateStudentLname(studentInfo_t *Student) {
    char str[20];
    Dprintf("Enter Student ( New ) last Name \n");
    gets(str);
    strcpy(Student->lastName, str);
}

systemStatus_t updateStudentGPA(studentInfo_t *Student) {
    Dprintf("Enter Student (New) GPA \n");
    scanf("%f", &Student->GPA);
}

systemStatus_t updateStudentCourses(studentInfo_t *Student) {
    Dprintf("Enter Student (New) Courses ID\n");
    for (int i = 0; i < 5; i++) {
        Dprintf("==> Enter Course %d ID \n", i + 1);
        scanf("%d", &Student->courseID[i]);
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


systemStatus_t systemCreate() {
    FIFO_init(&FIFO_info, mainBuff, buffSize);
    Dprintf("FIFO has been initialized successfully\n");
    Dprintf("=== WELCOME TO STUDENT MANAGEMENT SYSTEM ===\n");
    //systemPrintMenu();
    return System_noError;
}


systemStatus_t systemAddStudent_manually() {
    studentInfo_t *ptrStudent = systemCatchStudentData();
    if (ptrStudent) {
        FIFO_enqueue(&FIFO_info, *ptrStudent);
        Dprintf("[INFO] student roll %d has been added successfully\n", ptrStudent->roll);
        Dprintf("System stored %d student remains : %d student \n", FIFO_info.count, buffSize - FIFO_info.count);
        return System_noError;
    } else {
        return System_Error;
    }
}

systemStatus_t systemFindStudentRoll() {
    int i = 0, id;
    Dprintf("Enter Roll ID for the student \n");
    scanf("%d", (int *) &id);
    while (i < FIFO_info.count) {
        if (FIFO_info.tail[i].roll == id) {
            systemPrintStudent(&FIFO_info.tail[i]);
            return System_noError;
        }
        i++;
    }
    Dprintf("---------------------------------------------\n");
    Dprintf("[ERROR] : This ID doesn't exist \n");
    Dprintf("---------------------------------------------\n");
    return System_Error;

}

systemStatus_t systemFindStudentName() {
    int i = 0;
    char name[20];
    Dprintf("Enter first name for the student \n");
    gets(name);
    while (i < FIFO_info.count) {
        if (!strcmpi(name, FIFO_info.tail[i].firstName)) {
            systemPrintStudent(&FIFO_info.tail[i]);
            return System_noError;
        }
        i++;
    }
    Dprintf("---------------------------------------------\n");
    Dprintf("[ERROR] : This name doesn't exist \n");
    Dprintf("---------------------------------------------\n");
    return System_Error;
}

systemStatus_t systemFindStudentCourseID() {
    int i = 0, courseID, count = 0;
    studentInfo_t *ptrStudent = NULL;
    Dprintf("Enter Course ID \n");
    scanf("%d", (int *) &courseID);
    while (i < FIFO_info.count) {
        for (int j = 0; j < 5; j++) {
            if (FIFO_info.tail[i].courseID[j] == courseID) {
                ptrStudent = &FIFO_info.tail[i];
                Dprintf("The students registered this course ID are : \n");
                systemPrintStudent(ptrStudent);
                count++;
            }
        }
        i++;
    }
    if (ptrStudent) {
        Dprintf("Number of student register Course ID: (%d) are : (%d)\n", courseID, count);
        Dprintf("-----------------------------------------------------\n");
        return System_noError;
    } else {
        Dprintf("[INFO] : No student register this course  \n");
        return System_Error;
    }
}

systemStatus_t systemPrintAll() {
    ptrPrinterFnc = (systemStatus_t (*)(studentInfo_t *)) systemPrintStudent;
    FIFO_print(&FIFO_info);
    return System_noError;
}

systemStatus_t systemStatistics() {
    Dprintf("Maximum size of storage is : %d \n", buffSize);
    Dprintf("Number of students have been stored : %d student \n", FIFO_info.count);
    Dprintf("Number of students remain : %d\n", buffSize - FIFO_info.count);
    Dprintf("-----------------------------------------------------\n");
}

systemStatus_t loadDataFile() {
    FILE *infile;
    studentInfo_t tempStudent;
    infile = fopen("StudentData.txt", "r");
    if (infile == NULL) {
        fprintf(stderr, "\nError opening file\n");
        Dprintf("[ERROR] Can't open the file \n");
    }
    fscanf(infile, "%d", &tempStudent.roll);

    while (!feof(infile)) {
        fscanf(infile, "%d", &tempStudent.roll);
        if (!checkRollID(tempStudent.roll)) {
            fscanf(infile, "%s", tempStudent.firstName);
            fscanf(infile, "%s", tempStudent.lastName);
            fscanf(infile, "%f", &tempStudent.GPA);
            for (int i = 0; i < 5; i++) {
                fscanf(infile, "%d", &tempStudent.courseID[i]);
            }
            FIFO_enqueue(&FIFO_info, tempStudent);
            Dprintf("[INFO] student roll %d has been added successfully\n", tempStudent.roll);
            Dprintf("[INFO] System stored %d student remains : %d student \n", FIFO_info.count,
                    buffSize - FIFO_info.count);
        } else {
            fscanf(infile, "%*[^\n]");
        }
    }
    fclose(infile);
    return System_noError;
}

systemStatus_t systemDeleteStudent() {
    int i = 0, rollID;
    Dprintf("Enter Roll ID for the student \n");
    scanf("%d", &rollID);
    while (i < FIFO_info.count) {
        if (FIFO_info.tail[i].roll == rollID) {
            FIFO_delete_element(&FIFO_info, &FIFO_info.tail[i]);
            Dprintf("[INFO] Student roll %d has been deleted successfully \n", rollID);
            return System_noError;
        }
        i++;
    }
    Dprintf("---------------------------------------------\n");
    Dprintf("[ERROR] : This ID doesn't exist \n");
    Dprintf("---------------------------------------------\n");
    return System_Error;
}

systemStatus_t systemUpdateStudent() {
    int i = 0, rollID, choice;
    Dprintf("Enter Roll ID for the student \n");
    scanf("%d", &rollID);
    while (i < FIFO_info.count) {
        if (FIFO_info.tail[i].roll == rollID) {
            while (1) {
                printUpdateMenu();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        updateStudentRoll(&FIFO_info.tail[i]);
                        break;
                    case 2:
                        updateStudentFname(&FIFO_info.tail[i]);
                        break;
                    case 3:
                        updateStudentLname(&FIFO_info.tail[i]);
                        break;
                    case 4:
                        updateStudentGPA(&FIFO_info.tail[i]);
                        break;
                    case 5:
                        updateStudentCourses(&FIFO_info.tail[i]);
                        break;
                    case 6:
                        break;
                }
                Dprintf("[INFO] Student information has been updated successfully \n");
                if (choice == 6)break;
            }
            return System_noError;
        }
        i++;
    }
    Dprintf("---------------------------------------------\n");
    Dprintf("[ERROR] : This ID doesn't exist \n");
    Dprintf("---------------------------------------------\n");
    return System_Error;
}

systemStatus_t systemUpdateStudentFile() {

    FIFO_print_file(&FIFO_info);
    return System_noError;

}

systemStatus_t FIFO_print_file(FIFO_buf_t *fifo) {

    int i;
    element_type *ptrtemp;

    if (fifo->count == 0) {
        Dprintf("FIFO is empty\n");
    } else {
        ptrtemp = fifo->tail;
        Dprintf("\n================ printing in file  =============== \n");

        FILE *outfile;
        outfile = fopen("outfile.txt", "w");
        if (outfile == NULL) {
            fprintf(stderr, "\nError opening file\n");
            Dprintf("[ERROR] Can't open the file \n");
        }
        for (i = 0; i < fifo->count; i++) {

            fprintf(outfile, "%d ", ptrtemp->roll);
            fprintf(outfile, "%s ", ptrtemp->firstName);
            fprintf(outfile, "%s ", ptrtemp->lastName);
            fprintf(outfile, "%.2f ", ptrtemp->GPA);
            for (int j = 0; j < 5; j++) {
                fprintf(outfile, "%d ", ptrtemp->courseID[j]);
            }

            fprintf(outfile,"\n");

            if (ptrtemp == fifo->base + (fifo->length * sizeof(element_type)))
                ptrtemp = fifo->base;
            else
                ptrtemp++;

        }
        Dprintf("[INFO] Data saved to file successfully \n") ;
        fclose(outfile);
    }
}


/**********************************************************************************************************************
 *  END OF FILE: Management_System.c
 *********************************************************************************************************************/
