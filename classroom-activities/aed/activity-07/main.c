#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "../utils/show.h"
#include "airplanes-queue.h"
#include "airplanes-stack.h"

void init_main() {
    init_show();

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) printf("Running at %s", cwd);
    else perror("getcwd() error");

    endline();
}

void exercise01() {
    show_header("Exercise 01 - Airplanes Queue", CYAN);
    AirplanesQueue *queue = apqueue_create_queue();
    Airplane *a = apqueue_create_airplane(1302, "Airbus A380");
    Airplane *b = apqueue_create_airplane(9532, "Boeing 747");
    Airplane *c = apqueue_create_airplane(9842, "McDonnell Douglas MD-11");
    Airplane *d = apqueue_create_airplane(5728, "Lockheed L-1011 Tristar");
    Airplane *e = apqueue_create_airplane(2408, "Airbus A340");

    show_text_ln("Queue ", BLUE);
    apqueue_print_queue(queue);
    printf("(%d) airplanes", apqueue_get_len(queue));
    endline();

    apqueue_enqueue_airplane(queue, *a);

    apqueue_print_queue(queue);
    printf("(%d) airplanes", apqueue_get_len(queue));
    endline();
}

void exercise02() {
    show_header("Exercise 02 - Airplanes Stack", MAGENTA);
    AirplanesStack *stack = apstack_create_stack();
    Airplane_v2 popped;

    show_text("Stack 0 - nothing", MAGENTA);
    apstack_print_stack(stack);

    show_text("Stack 1 - adding 5", MAGENTA);
    Airplane_v2 *a = apstack_create_airplane(1302, "Airbus A380");
    Airplane_v2 *b = apstack_create_airplane(9532, "Boeing 747");
    Airplane_v2 *c = apstack_create_airplane(9842, "McDonnell Douglas MD-11");
    Airplane_v2 *d = apstack_create_airplane(5728, "Lockheed L-1011 Tristar");
    Airplane_v2 *e = apstack_create_airplane(2408, "Airbus A340");
    apstack_push_airplane(stack, *a);
    apstack_push_airplane(stack, *b);
    apstack_push_airplane(stack, *c);
    apstack_push_airplane(stack, *d);
    apstack_push_airplane(stack, *e);
    apstack_print_stack(stack);

    show_text("Stack 2 - popping", MAGENTA);
    popped = apstack_pop_airplane(stack);
    apstack_print_stack(stack);
    show_text_ln("Airplane - popped", BLUE);
    apstack_print_airplane(popped);

    show_text("Stack 2 - adding 5", MAGENTA);
    Airplane_v2 *f = apstack_create_airplane(4228, "Boeing 777");
    Airplane_v2 *g = apstack_create_airplane(1390, "Ilyushin Il-86");
    Airplane_v2 *h = apstack_create_airplane(3811, "Ilyushin Il-96");
    Airplane_v2 *i = apstack_create_airplane(5372, "Airbus 787");
    Airplane_v2 *j = apstack_create_airplane(8284, "McDonnell Douglas DC-10");
    apstack_push_airplane(stack, *f);
    apstack_push_airplane(stack, *g);
    apstack_push_airplane(stack, *h);
    apstack_push_airplane(stack, *i);
    apstack_push_airplane(stack, *j);
    apstack_print_stack(stack);

    show_text("Stack 2 - popping airplane from 3rd position", MAGENTA);
    popped = apstack_pop_airplane_at(stack, 3);
    apstack_print_stack(stack);
    show_text_ln("Airplane - popped", BLUE);
    apstack_print_airplane(popped);
}

int main() {
    init_main();

//    exercise01();
    exercise02();

    return 0;
}