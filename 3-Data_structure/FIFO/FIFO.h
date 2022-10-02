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

// USER configuration
//select  element type
#define element_typy uint8_t
#define width1 (unsigned int)5
//create buffer
element_typy uart_buff[width1];


//fifo data types

typedef struct {
	unsigned int length ;
	unsigned int count ;
	element_typy *head ;
	element_typy *base ;
	element_typy *tail ;
}FIFO_buf_t;

typedef enum {
	FIFO_no_error ,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_status;


// API's

FIFO_status FIFO_init(FIFO_buf_t* fifo ,element_typy* buf,unsigned int length) ;
FIFO_status FIFO_enqueue(FIFO_buf_t* fifo ,element_typy item) ;
FIFO_status FIFO_dequeue(FIFO_buf_t* fifo ,element_typy* item) ;
FIFO_status FIFO_is_full(FIFO_buf_t* fifo) ;
void FIFO_print(FIFO_buf_t* fifo) ;


#endif /* FIFO_H_ */
