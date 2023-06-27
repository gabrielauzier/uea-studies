/*
 * Airplanes Stack (apstack)
 *
 * Implemented using Simple Dynamic Stack (apstack)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 50

#include "airplanes-stack.h"
#include "../utils/show.h"

AirplanesStack * apstack_create_stack() {
    AirplanesStack *src = malloc(sizeof (AirplanesStack));
    src->top = NULL;
    return src;
}

Airplane_v2 * apstack_create_airplane(int id, char *name) {
    Airplane_v2 *src = malloc(sizeof (Airplane_v2));
    src->id = id;
    strcpy(src->name, name);
    return src;
}

void apstack_push_airplane(AirplanesStack *src, Airplane_v2 newNode) {
    AirplanesStackElement *newElement = malloc(sizeof (AirplanesStackElement));
    newElement->node = newNode;
    newElement->next = src->top;
    src->top = newElement;
}

Airplane_v2 apstack_pop_airplane(AirplanesStack *src) {
    AirplanesStackElement *top = src->top;
    Airplane_v2 topNode = top->node;
    src->top = src->top->next;
    free(top);
    return topNode;
}

int apstack_get_stack_len(AirplanesStack *src) {
    AirplanesStackElement *crawler = src->top;
    int len = 0;
    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }
    return len;
}

Airplane_v2 apstack_pop_airplane_at(AirplanesStack *src, int removeAt) {
    AirplanesStack *temp = apstack_create_stack();
    int len = apstack_get_stack_len(src);
    int counter = len - removeAt;

    for (int i = 0; i < counter; i++)
        apstack_push_airplane(temp, apstack_pop_airplane(src));

    Airplane_v2 out = apstack_pop_airplane(src);

    for (int i = 0; i < counter; i++)
        apstack_push_airplane(src, apstack_pop_airplane(temp));

    return out;
}

Airplane_v2 apstack_peek_airplane(AirplanesStack *src) {
    return src->top->node;
}

int apstack_is_empty(AirplanesStack *src) {
    return (src->top == NULL) ? 1 : 0;
}

void apstack_print_stack(AirplanesStack *src) {
    endline();
    endline();

    AirplanesStackElement *crawler = src->top;
    char text[255];

    show_start(MAGENTA, BLACK);
    show_text_align_center("TOP", MAX_LINE_SIZE);
    show_close();
    endline();
    endline();

    if (apstack_is_empty(src)) {
        show_start(BLUE, BLACK);
        sprintf(text, "NULL");
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();
        endline();
    }

    while (crawler != NULL) {
        show_start(BLUE, BLACK);
        sprintf(text, "airplane.id: %d", crawler->node.id);
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();

        show_start(BLUE, BLACK);
        sprintf(text, "airplane.name: %s", crawler->node.name);
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();

        endline();
        crawler = crawler->next;
    }

    show_close();
}

void apstack_print_airplane(Airplane_v2 node) {
    endline();
    char text[255];
    show_start(BLUE, BLACK);
    sprintf(text, "value: %d", node.id);
    show_text_align_center(text, MAX_LINE_SIZE);
    show_close();
    endline();

    show_start(BLUE, BLACK);
    sprintf(text, "name: %s", node.name);
    show_text_align_center(text, MAX_LINE_SIZE);
    show_close();
    endline();

    endline();
}