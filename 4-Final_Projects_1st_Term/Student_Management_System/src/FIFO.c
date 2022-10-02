/*
 * FIFO.c
 *
 *  Created on: 12 Sept 2022
 *      Author: MAshr
 */
#include"FIFO.h"

FIFO_status FIFO_init(FIFO_buf_t *fifo, element_type *buf, unsigned int length) {

    if (buf == NULL)
        return FIFO_null;

    fifo->base = buf;
    fifo->tail = buf;
    fifo->head = buf;
    fifo->count = 0;
    fifo->length = length;

    return FIFO_no_error;
}

FIFO_status FIFO_enqueue(FIFO_buf_t *fifo, element_type item) {

    if (!fifo->base || !fifo->tail || !fifo->head)
        return FIFO_null;
    if (FIFO_is_full(fifo) == FIFO_full)
        return FIFO_full;

    *(fifo->head) = item;
    if (fifo->head == fifo->base + (fifo->length * sizeof(element_type)))
        fifo->head = fifo->base;
    else
        fifo->head++;

    fifo->count++;
    return FIFO_no_error;
}


FIFO_status FIFO_dequeue(FIFO_buf_t *fifo, element_type *item) {

    if (!fifo->base || !fifo->tail || !fifo->head)
        return FIFO_null;
    if (fifo->count == 0)
        return FIFO_empty;

    *item = *fifo->tail;
    fifo->count--;

    if (fifo->tail == fifo->base + (fifo->length * sizeof(element_type)))
        fifo->tail = fifo->base;
    else
        fifo->tail++;


    return FIFO_no_error;
}

FIFO_status FIFO_is_full(FIFO_buf_t *fifo) {

    if (!fifo->base || !fifo->tail || !fifo->head)
        return FIFO_null;
    if (fifo->count == fifo->length)
        return FIFO_full;
    else return FIFO_no_error;
}

void FIFO_print(FIFO_buf_t *fifo) {

    int i;
    element_type *ptrtemp;

    if (fifo->count == 0)
    {
        Dprintf("FIFO is empty\n");
    }
    else {
        ptrtemp = fifo->tail;
        Dprintf("\n================ print =============== \n");
        for (i = 0; i < fifo->count; i++) {
           // Dprintf("\t (%x) \n", *ptrtemp);
            ptrPrinterFnc(ptrtemp);
            ptrtemp++;
        }
    }
}

FIFO_status FIFO_delete_element(FIFO_buf_t* fifo,element_type* item)
{
    if (!fifo->base || !fifo->tail || !fifo->head)
        return FIFO_null;
    if (fifo->count == 0)
        return FIFO_empty;
int i= 0 ;

    while (item < fifo->head)
    {
        *item=*(item+1);

        if (item == fifo->base + (fifo->length * sizeof(element_type)))
            item = fifo->base;
        else
            item++;
    }
    fifo->count-- ;

    if (fifo->head == fifo->base)
        fifo->head = fifo->base + (fifo->length * sizeof (element_type));
    else
        fifo->head--;
    return FIFO_no_error ;
}
