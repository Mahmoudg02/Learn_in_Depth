/*
 * main.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */
#include<stdio.h>
#include"LIFO.h"
#include <stdlib.h>


unsigned int buff1[5];

int main(int argc, char **argv) {
	unsigned int i ,temp ;

	LIFO_BUF_t uart_lifo ,i2c_lifo;
	//static
	LIFO_init(&uart_lifo,buff1,sizeof(buff1)/sizeof(unsigned int));
	//dynamic
	unsigned int *buff2= (unsigned int *) malloc( 5*sizeof(unsigned int ));
	LIFO_init(&uart_lifo,buff2,5);


	for(i = 0 ;i<5;i++)
	{
		if (LIFO_add_item(&uart_lifo,i)==LIFO_no_error)
			printf("item %d added \n",i);
	}

	for(i = 0 ;i<5;i++)
	{
		if (LIFO_get_item(&uart_lifo,&temp)==LIFO_no_error)
			printf("pushed = %d \n",temp);
	}

}
