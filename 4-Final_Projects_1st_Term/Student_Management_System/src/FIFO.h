/*
 * FIFO.h
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#ifndef FIFO_H_
#define FIFO_H_

#include<stdio.h>
#include<stdint.h>

#include "FIFO_config.h"

#define Dprintf(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin)

//create buffer

element_type uart_buff[buffSize];

typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_type *head ;
	element_type *base ;
	element_type *tail ;
}FIFO_buf_t;

typedef enum {
	FIFO_no_error ,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_status;


// API's

FIFO_status FIFO_init(FIFO_buf_t* fifo , element_type* buf, unsigned int length) ;
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo , element_type item) ;
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo , element_type* item) ;
FIFO_status FIFO_is_full(FIFO_buf_t* fifo) ;
void FIFO_print(FIFO_buf_t* fifo) ;
FIFO_status FIFO_delete_element(FIFO_buf_t* fifo, element_type* item);


#endif /* FIFO_H_ */
