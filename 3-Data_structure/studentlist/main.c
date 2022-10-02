/*
 * main.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define Dprintf(...)		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}


int main(void)
{
    char temp[40];

    while (1)
    {
        Dprintf("============================\n");
        Dprintf("chose from the following options \n");
        Dprintf("1: Add Student \n");
        Dprintf("2: Delete Student \n");
        Dprintf("3: Print Students \n");
        Dprintf("4: Delete All \n");
        printf("enter option number \n");
        fflush(stdin);
        fflush(stdout);


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
            Dprintf("wrong option \n");
            break;
        }
    }
    return 0;
}

