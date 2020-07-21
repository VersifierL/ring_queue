#include "ring_queue.h"
#include "stdio.h"

/*
 * function: initialize ring queue
 * para: ring queue structure pointer
 * return: void
 */
void ring_queue_init(RING_QUEUE *ring_queue_t)
{
    ring_queue_t->head = 0;
    ring_queue_t->rear = 0;
    ring_queue_t->length = 0;
}

/*
 * function: write one char to ring queue
 * para1: ring queue structure pointer
 * para2: the data to write
 * return: void
 */
void ring_queue_write(RING_QUEUE *ring_queue_t, char data)
{
    ring_queue_t->ring_buff[ring_queue_t->rear] = data; //write data to the rear of queue
    ring_queue_t->rear = (ring_queue_t->rear+1)%RING_QUEUE_LENGTH;//point the new rear of queue
    ring_queue_t->length ++;
}

/*
 * function: read one char from ring queue
 * para1: ring queue structure pointer
 * return: void
 */
void ring_queue_read(RING_QUEUE *ring_queue_t)
{
    ring_queue_t->head = (ring_queue_t->head+1)%RING_QUEUE_LENGTH;
    ring_queue_t->length--;
}

/*
 * function: get the current length of ring queue
 * para1: ring queue structure pointer
 * return: length
 */
int ring_queue_length_get(RING_QUEUE *ring_queue_t)
{
    return ring_queue_t->length;
}

/*
 * function: determine if the queue is full
 * para1: ring queue structure pointer
 * return: 1 -> yes
           0 -> no
 */
int ring_queue_is_full(RING_QUEUE *ring_queue_t)
{
    return (ring_queue_t->length == RING_QUEUE_LENGTH);
}

/*
 * function: determine if the queue is empty
 * para1: ring queue structure pointer
 * return: 1 -> yes
           0 -> no
 */
int ring_queue_is_empty(RING_QUEUE *ring_queue_t)
{
    return (ring_queue_t->length == 0);
}

/*
 * function: print the ring queue
 * para1: ring queue structure pointer
 * return: void
 */
void ring_queue_read_all(RING_QUEUE *ring_queue_t)
{
    int i;
    int len = ring_queue_length_get(ring_queue_t);
    printf("Length:%d\n",len);
    for(i=0; i<len; i++)
    {
        printf("%c", ring_queue_t->ring_buff[i]);
    }
}

/*
 * function: copy the ring queue
 * para1: ring queue structure pointer
 * return: ring queue data pointer
 */
char* ring_queue_copy(RING_QUEUE *ring_queue_t)
{
   return ring_queue_t->ring_buff;
}



