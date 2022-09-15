/*
 * LIFO.h
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */

#ifndef LIFO_H_
#define LIFO_H_

/*
 * DATA types
 */

typedef struct{
	unsigned int length;
	unsigned int count ;
	unsigned int* base ;
	unsigned int* head ;

}LIFO_BUF_t;

typedef enum{
	LIFO_no_error ,
	LIFO_full,
	LIFO_empty,
	LIFO_null,
}LIFO_status;

LIFO_status LIFO_add_item(LIFO_BUF_t*,unsigned int data);
LIFO_status LIFO_get_item(LIFO_BUF_t*,unsigned int *item);
LIFO_status LIFO_init(LIFO_BUF_t*,unsigned int *buff,unsigned int length);

#endif /* LIFO_H_ */
