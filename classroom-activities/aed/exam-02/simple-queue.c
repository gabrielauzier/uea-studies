#include <stdio.h>
#include <stdlib.h>

#include "simple-queue.h"
#include "../utils/show.h"

SimpleQueue * sq_create_queue() {
    SimpleQueue *src = malloc(sizeof (SimpleQueue));
    src->front = NULL;
    src->back = NULL;
    src->len = 0;
    return src;
}

SimpleQueueNode * sq_create_node(int value) {
    SimpleQueueNode *src = malloc(sizeof (SimpleQueueNode));
    src->value = value;
    return src;
}

int sq_is_empty(SimpleQueue *src) {
    return (src->front == NULL) ? 1 : 0;
}

void sq_enqueue_node(SimpleQueue *src, SimpleQueueNode newNode) {
    SimpleQueueElement *newElement = malloc(sizeof (SimpleQueueElement));

    newElement->node = newNode;
    newElement->next = NULL;

    if (src->front == NULL) src->front = newElement; else src->back->next = newElement;

    src->len++;
    src->back = newElement;
}

SimpleQueueNode * sq_dequeue_node(SimpleQueue *src) {
    if (sq_is_empty(src)) return NULL;

    SimpleQueueElement *first = src->front;
    src->front = src->front->next;
    src->len--;

    return &first->node;
}


void sq_print_queue(SimpleQueue *src) {
    endline();
    SimpleQueueElement *crawler = src->front;

    show_highlight(" FRONT ", BLUE, BLACK);
    printf(" --> ");

    if (sq_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    while (crawler != NULL) {
        char text[255];
        sprintf(text, " %d ", crawler->node.value);
        show_highlight(text, CYAN, BLACK);

        crawler = crawler->next;
        if (crawler != NULL) printf(" --> ");
    }

    endline();
}

void sq_print_node(SimpleQueueNode *src, char *title) {
    endline();

    show_text(title, NORMAL);
    char text[255];
    sprintf(text, " %d ", src->value);
    show_highlight(text, WHITE, BLACK);

    endline();
}

void sq_fill_queue(SimpleQueue *queue, int *values, int values_len) {
    for (int i = 0; i < values_len; i++) {
        SimpleQueueNode *new_node = sq_create_node(values[i]);
        sq_enqueue_node(queue, *new_node);
    }
}