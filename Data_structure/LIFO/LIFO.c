/*
 * LIFO.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#include "LIFO.h"
#include<stdio.h>

LIFO_status LIFO_add_item(LIFO_BUF_t* lifo_buff,unsigned int data){

	//check lifo is valid
	if(!lifo_buff->base || !lifo_buff->head )
		return LIFO_null ;

	//check lifo is full
//	if(lifo_buff->head >= (lifo_buff->base + (lifo_buff->length) * sizeof(unsigned int) ))
//		return LIFO_full;
	if(lifo_buff->count>=lifo_buff->length)
		return LIFO_full;
	//Add item
	*(lifo_buff->head)=data ;
	lifo_buff->head++ ;
	lifo_buff->count++ ;

	return LIFO_no_error ;
}
LIFO_status LIFO_get_item(LIFO_BUF_t* lifo_buff,unsigned int* item){
	//check lifo valid
	if(!lifo_buff->base || !lifo_buff->head )
			return LIFO_null ;
	// check lifo is empty
	if(lifo_buff->count==0)
		return LIFO_empty ;
	lifo_buff->head-- ;
	*item = *lifo_buff->head ;
	lifo_buff->count-- ;


	return LIFO_no_error ;
}
LIFO_status LIFO_init(LIFO_BUF_t* lifo_buff,unsigned int *buff ,unsigned int length){

	if(buff == NULL)
		return LIFO_null ;

	lifo_buff->base =buff ;
	lifo_buff->head=buff ;
	lifo_buff->length=length;
	lifo_buff->count =0 ;

	return LIFO_no_error ;
}
