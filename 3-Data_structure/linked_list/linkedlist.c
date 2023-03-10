/*
 * linkedlist.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#include "linkedilist.h"
#include<stdlib.h>


void AddStudent(void)
{
    SStudent *pNewStudent, *pLastStudent;
    // check is the linked list empty
    if (gpFirstStudent == NULL)
    {
        // create new record
        pNewStudent = (SStudent *)malloc(sizeof(SStudent));
        gpFirstStudent = pNewStudent;
    }
    else
    {
        // navigate until reach last student
        pLastStudent = gpFirstStudent;
        while (pLastStudent->nextStudent)
        {
            pLastStudent = pLastStudent->nextStudent;
        }
        pNewStudent = (SStudent *)malloc(sizeof(SStudent));
        pLastStudent->nextStudent = pNewStudent;
    }

    fill_record(pNewStudent);
    pNewStudent->nextStudent = NULL;
}

void fill_record(SStudent *pNewStudent)
{
    char temp_text[40];
    printf("enter student ID");
    gets(temp_text);
    pNewStudent->student.id = atoi(temp_text);

    printf("enter student name ");
    gets(pNewStudent->student.name);

    printf("enter student degree ");
    gets(temp_text);
    pNewStudent->student.h_degree = atof(temp_text);
}

int delete_record(void)
{
    int id;
    char temp_text[40];
    SStudent *currentStudent = gpFirstStudent;
    SStudent *perviosStudent = NULL;

    printf("enter student ID to delete ");
    gets(temp_text);
    id = atoi(temp_text);

    if (currentStudent->nextStudent)
    {
        while (currentStudent->nextStudent)
        {
            if (currentStudent->student.id == id)
            {
                if (perviosStudent)
                {
                    perviosStudent->nextStudent = currentStudent->nextStudent;
                    currentStudent->nextStudent = NULL;
                }
                else
                {
                    gpFirstStudent = currentStudent->nextStudent;
                }
                free(currentStudent);
                return 1;
            }
            else
            {
                perviosStudent = currentStudent;
                currentStudent = currentStudent->nextStudent;
            }
        }
        printf("can not find the student id ");
    }
    else
    {
        printf("list is empty");
    }
    return 0;
}

int print_student_list(void)
{
    SStudent *temp = gpFirstStudent;
    int count = 1;
    if (temp->nextStudent == NULL)
    {
        printf("empty list \n");
        return 1;
    }
    while (temp->nextStudent)
    {
        printf("========== student no : %d  ===========\n", count);
        printf("ID : %d\n", temp->student.id);
        printf("name : %s\n", temp->student.name);
        printf("H.degree : %f\n", temp->student.h_degree);
        count++;
        temp = temp->nextStudent;
    }
    return 0;
}

void delete_all_list(void)
{
    SStudent *temp_current = gpFirstStudent;
    if (temp_current->nextStudent == NULL)
    {
        printf("empty list \n");

    }
    else
    {

        while (temp_current->nextStudent)
        {
            SStudent *temp = temp_current;
            temp_current = temp_current->nextStudent;
            free(temp);
        }
    }
    gpFirstStudent =NULL ;
}
