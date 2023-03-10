/*
 * main.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedilist.h"



int main(void)
{
    char temp[40];

    while (1)
    {
        printf("============================\n");
        printf("chose from the following options \n");
        printf("1: Add Student \n");
        printf("2: Delete Student \n");
        printf("3: Print Students \n");
        printf("4: Delete All \n");
        printf("enter option number \n");

        gets(temp);
        switch (atoi(temp))
        {
        case 1:
            AddStudent();
            break;
        case 2:
            delete_record();
            break;
        case 3:
            print_student_list();
            break;
        case 4:
            delete_all_list();
            break;
        default:
            printf("wrong option \n");
            break;
        }
    }
    return 0;
}
