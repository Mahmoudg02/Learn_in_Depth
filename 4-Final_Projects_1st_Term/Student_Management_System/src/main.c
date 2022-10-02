/*
 * main.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */
#include "Management_System.h"
#include "stdlib.h"
int main(void) {
    int choice;
    systemCreate();
    while (1) {
        systemPrintMenu();
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                systemAddStudent_manually();
                break;
            case 2:
                loadDataFile();
                break;
            case 3:
                systemFindStudentRoll();
                break;
            case 4:
                systemFindStudentName();
                break;
            case 5:
                systemFindStudentCourseID();
                break;
            case 6:
                systemStatistics();
                break;
            case 7:
                systemDeleteStudent();
                break;
            case 8:
                systemUpdateStudent();
                break;
            case 9:
                systemPrintAll();
                break;
            case 10:
                systemUpdateStudentFile();
                break;
            case 11:
                exit(1);
        }
    }
}
