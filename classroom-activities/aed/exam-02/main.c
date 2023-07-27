/*
 * Exam 14.07.2023
 * */

#include <stdio.h>
#include <time.h>

#include "simple-queue.h"
#include "../utils/show.h"

#define array_len(x) (sizeof(x) / sizeof((x)[0]))


void init_main_() {
    init_show();

    time_t now;
    time(&now);

    char date[200];
    sprintf(date, "Delivered at %s", ctime(&now));

    show_text(date, MAGENTA);
    show_text_ln("by Gabriel Vasconcelos Auzier", MAGENTA);
    show_header("Code 001 - Queue intercalation (Simple Queue)", MAGENTA);
}


int main() {
    init_main_();

    SimpleQueue *queue1 = sq_create_queue();
    SimpleQueue *queue2 = sq_create_queue();

    int values1[] = { 1, 3, 5, 7 };
    int values2[] = { 2, 4, 6, 8 };

    sq_fill_queue(queue1, values1, array_len(values1));
    sq_fill_queue(queue2, values2, array_len(values2));

    show_text("Queue 1", MAGENTA);
    sq_print_queue(queue1);
    endline();

    show_text("Queue 2", MAGENTA);
    sq_print_queue(queue2);
    endline();

    SimpleQueueNode *tmp;
    SimpleQueue *result = sq_create_queue();
    while (sq_is_empty(queue1) != 1 && sq_is_empty(queue2) != 1) {
        tmp = sq_dequeue_node(queue1);
        sq_enqueue_node(result, *tmp);
        tmp = sq_dequeue_node(queue2);
        sq_enqueue_node(result, *tmp);
    }

    show_text("Queue 3 (result)", MAGENTA);
    sq_print_queue(result);
    return 0;
}