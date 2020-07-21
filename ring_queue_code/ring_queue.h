#define RING_QUEUE_LENGTH 5
/*the structure of ring queue*/
typedef struct
{
    int head;
    int rear;
    int length;
    char ring_buff[RING_QUEUE_LENGTH];
}RING_QUEUE;

void ring_queue_init(RING_QUEUE *ring_queue_t);
void ring_queue_write(RING_QUEUE *ring_queue_t,char data);
void ring_queue_read(RING_QUEUE *ring_queue_t);
int ring_queue_length_get(RING_QUEUE *ring_queue_t);
int ring_queue_is_full(RING_QUEUE *ring_queue_t);
int ring_queue_is_empty(RING_QUEUE *ring_queue_t);
void ring_queue_read_all(RING_QUEUE *ring_queue_t);
char* ring_queue_copy(RING_QUEUE *ring_queue_t);
