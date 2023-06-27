/* Airplanes Queue (apqueue) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/show.h"
#include "airplanes-queue.h"

AirplanesQueue * apqueue_create_queue() {
    AirplanesQueue *src = malloc(sizeof (AirplanesQueue));
    src->front = NULL;
    src->back = NULL;
    src->len = 0;
    return src;
}

Airplane * apqueue_create_airplane(int id, char *name) {
    Airplane *src = malloc(sizeof (Airplane));
    src->id = id;
    strcpy(src->name, name);
    return src;
}

int apqueue_is_empty(AirplanesQueue *src) {
    return (src->front == NULL) ? 1 : 0;
}

int apqueue_get_len(AirplanesQueue *src) {
    return src->len;
}

void apqueue_enqueue_airplane(AirplanesQueue *src, Airplane newAirplane) {
    AirplanesQueueElement *newElement = malloc(sizeof (AirplanesQueueElement));

    newElement->airplane = newAirplane;
    newElement->next = NULL;

    if (src->front == NULL) src->front = newElement; else src->back->next = newElement;

    src->len++;
    src->back = newElement;
}

Airplane * apqueue_dequeue_airplane(AirplanesQueue *src) {
    if (apqueue_is_empty(src)) return NULL;

    AirplanesQueueElement *first = src->front;
    src->front = src->front->next;
    src->len--;

    return &first->airplane;
}


void apqueue_print_queue(AirplanesQueue *src) {
    endline();
    AirplanesQueueElement *crawler = src->front;

    show_highlight(" FRONT ", BLUE, BLACK);
    printf(" --> ");

    if (apqueue_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    while (crawler != NULL) {
        char text[255];
        sprintf(text, " %d ", crawler->airplane.id);
        show_highlight(text, CYAN, BLACK);

        crawler = crawler->next;
        if (crawler != NULL) printf(" --> ");
    }

    endline();
}

void apqueue_print_airplane(Airplane *src, char *title) {
    endline();

    show_text(title, NORMAL);
    char text[255];
    sprintf(text, " (%d) %s ", src->id, src->name);
    show_highlight(text, WHITE, BLACK);

    endline();
}
