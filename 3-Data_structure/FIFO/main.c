/*
 * main.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */
#include<stdio.h>
#include "FIFO.h"

int main(void) {

	element_typy temp ;
	FIFO_buf_t fifo_uart ;
	if(FIFO_init(&fifo_uart,uart_buff, width1) == FIFO_no_error)
		printf("fifo init ---------- done \n") ;

	for(int i =0 ;i < 7; i++)
	{
		if(FIFO_enqueue(&fifo_uart, i)==FIFO_no_error)
		printf("enqueue (%d) = (%x) \n",i,(element_typy)i) ;
		else
			printf("enqueue failed  \n") ;

	}

	FIFO_print(&fifo_uart) ;

	if(FIFO_dequeue(&fifo_uart, &temp)==FIFO_no_error)
	printf("fifo dequeue (%x)",temp) ;
	if(FIFO_dequeue(&fifo_uart, &temp)==FIFO_no_error )
	printf("fifo dequeue (%x)",temp) ;

	FIFO_print(&fifo_uart) ;



	return 0 ;

}
