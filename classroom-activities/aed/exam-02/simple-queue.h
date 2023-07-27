/*
 * Simple Queue (sq)
 *
 * Implemented using Simple (Dynamic) Queue
 *
 * Basic operations for queue: create, enqueue, dequeue, isEmpty, isFull, size
 *
 * */

typedef struct SimpleQueueNode {
    int value;
} SimpleQueueNode;

typedef struct SimpleQueueElement {
    SimpleQueueNode node;
    struct SimpleQueueElement *next;
} SimpleQueueElement;

typedef struct SimpleQueue {
    SimpleQueueElement *front;
    SimpleQueueElement *back;
    int len;
} SimpleQueue;

SimpleQueue * sq_create_queue();
SimpleQueueNode * sq_create_node(int value);

int sq_is_empty(SimpleQueue *src);

void sq_enqueue_node(SimpleQueue *src, SimpleQueueNode newNode);
SimpleQueueNode * sq_dequeue_node(SimpleQueue *src);

void sq_print_queue(SimpleQueue *src);
void sq_print_node(SimpleQueueNode *src, char *title);
void sq_fill_queue(SimpleQueue *queue, int *values, int values_len);
