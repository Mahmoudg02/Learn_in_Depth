/*
 * linkedilist.h
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#ifndef LINKEDILIST_H_
#define LINKEDILIST_H_

#include <stdio.h>

/* -------------------------------------------------------------------------- */
/*                                 USED TYPES                                 */
/* -------------------------------------------------------------------------- */

typedef struct
{
    int id;
    char name[50];
    float h_degree;
} SData;

typedef struct student
{
    SData student;
    struct student *nextStudent;
} SStudent;

/* -------------------------------------------------------------------------- */
/*                                 GLOPAL VARS                                */
/* -------------------------------------------------------------------------- */

SStudent *gpFirstStudent = NULL;

/* -------------------------------------------------------------------------- */
/*                                 GLOPAL APIs                                */
/* -------------------------------------------------------------------------- */

void AddStudent(void);
void fill_record(SStudent *);
SStudent* search_id(int id);
int delete_record(void ) ;
int print_student_list(void);
void delete_all_list(void);

#endif /* LINKEDILIST_H_ */
