/*
 * FIFO.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */
#include"FIFO.h"


FIFO_status FIFO_init(FIFO_buf_t* fifo ,element_typy* buf,unsigned int length){

	if(buf==NULL)
		return FIFO_null ;

	fifo->base =buf ;
	fifo->tail =buf ;
	fifo->head =buf ;
	fifo->count =0 ;
	fifo->length =length ;

	return FIFO_no_error ;
}

FIFO_status FIFO_enqueue(FIFO_buf_t* fifo ,element_typy item){

	if(!fifo->base || !fifo->tail || !fifo->head)
		return FIFO_null ;
	if(FIFO_is_full(fifo) == FIFO_full)
		return FIFO_full ;

	*(fifo->head)=item ;
	if(fifo->head==fifo->base+(fifo->length*sizeof(element_typy)))
		fifo->head=fifo->base ;
	else
		fifo->head ++ ;

	fifo->count ++ ;
	return FIFO_no_error ;
}


FIFO_status FIFO_dequeue(FIFO_buf_t* fifo ,element_typy* item) {

	if(!fifo->base || !fifo->tail || !fifo->head)
		return FIFO_null ;
	if(fifo->count==0)
		return FIFO_empty ;

	*item=*fifo->tail ;
	fifo->count-- ;

	if(fifo->tail==fifo->base+(fifo->length*sizeof(element_typy)))
		fifo->tail=fifo->base ;
	else
		fifo->tail ++ ;


	return FIFO_no_error ;
}
FIFO_status FIFO_is_full(FIFO_buf_t* fifo){

	if(!fifo->base || !fifo->tail || !fifo->head)
		return FIFO_null ;
	if (fifo->count == fifo->length)
		return FIFO_full ;
	else return FIFO_no_error ;
}
void FIFO_print(FIFO_buf_t* fifo){

	int i ;
	element_typy *temp ;

	if(fifo->count==0)
		printf("fifo is empty") ;
	else
	{
		temp = fifo->tail ;
		printf("\n================ print =============== \n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t (%x) \n",*temp) ;
			temp ++ ;
		}
	}
}
