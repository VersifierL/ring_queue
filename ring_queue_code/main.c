/**
author:VersifierL
date:2020/06/24
version:1.0
function:FIFO, RING_QUEUE.
comment:
1.UnderScoreCase
2._t stand for structure
3.structure typedef and define all is uppercase.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ring_queue.h"
int main()
{
    RING_QUEUE ring_queue_t;
    ring_queue_init(&ring_queue_t); //initialize

    //write data to queue
    int i;
    for(i=0; i<10; i++) //write "0123456789". because the length of ring queue is 5, the result is "56789"
    {
        if(ring_queue_is_full(&ring_queue_t)) // if ring queue is full, remove the head data and add the rear data.
        {
             ring_queue_read(&ring_queue_t);
        }
        ring_queue_write(&ring_queue_t, i+'0');
    }

    //copy to data
    char data[RING_QUEUE_LENGTH];
    for(i=0; i<sizeof(data); i++)
    {
        data[i] = *(ring_queue_copy(&ring_queue_t)+i);
        printf("%c", data[i]);
    }
    return 0;
}
