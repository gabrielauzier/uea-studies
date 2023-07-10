/* Students Deck (stdeck)
 *
 * Implemented using deck (Doubled Ended Queue)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students-deck.h"
#include "../../../utils/show.h"

StudentsDeck * stdeck_create_queue() {
    StudentsDeck *new = malloc(sizeof (StudentsDeck));
    new->head = malloc(sizeof (StudentsDeckElement));
    new->head->next = NULL;
    new->head->previous = NULL;
    new->head->node = *stdeck_create_node(0, 0, "empty");

    new->len = 0;
    return new;
}

StudentsDeckNode * stdeck_create_node(int id, int pos, char *name) {
    StudentsDeckNode *src = malloc(sizeof (StudentsDeckNode));
    src->id = id;
    src->pos = pos;
    strcpy(src->name, name);
    return src;
}

int stdeck_is_empty(StudentsDeck *src) {
    return (src->head->next == NULL || src->head->previous == NULL);
}

int stdeck_start_exists(StudentsDeck *src) {
    return (src->head->next != NULL);
}

int stdeck_end_exists(StudentsDeck *src) {
    return (src->head->previous != NULL);
}

void stdeck_enqueue_node_at_start(StudentsDeck *src, StudentsDeckNode newNode) {
    StudentsDeckElement *newElement = malloc(sizeof (StudentsDeckElement));

    newElement->node = newNode;
    newElement->next = src->head->next;
    newElement->previous = src->head;
    newElement->next->previous = newElement;
    src->head->next = newElement;

    src->len++;
}

void stdeck_enqueue_node_at_end(StudentsDeck *src, StudentsDeckNode newNode) {
    StudentsDeckElement *newElement = malloc(sizeof (StudentsDeckElement));

    stdeck_print_element(src->head, "StudentsDeck Head");
    newElement->node = newNode;
    if (stdeck_start_exists(src))
        newElement->previous = src->head->next;
    else
        newElement->previous = src->head;

    newElement->next = src->head;
    src->head->previous = newElement;
    newElement->previous->next = newElement;


    src->len++;
}

StudentsDeckNode * stdeck_dequeue_node_at_start(StudentsDeck *src) {
    if (!stdeck_start_exists(src)) return NULL;

    StudentsDeckElement *first = src->head->next;
    StudentsDeckElement *out = src->head->next;

    src->head->next = first->next;
    first->next->previous = src->head;
    src->len--;

    free(first);
    return &out->node;
}

StudentsDeckNode * stdeck_dequeue_node_at_end(StudentsDeck *src) {
    if (!stdeck_end_exists(src)) return NULL;

    StudentsDeckElement *last = src->head->previous;
    StudentsDeckElement *out = src->head->previous;

    src->head->previous = last->previous;
    last->previous->next = src->head;
    src->len--;

    free(last);
    return &out->node;
}

void stdeck_print_queue(StudentsDeck *src) {
    endline();
    StudentsDeckElement *crawler = src->head;
    int lineSize = (src->len - 1) * 9 ;

    show_highlight(" HEAD ", BLUE, BLACK);
    printf(" --- ");

    if (stdeck_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    crawler = crawler->next;

    while (crawler != NULL && crawler->node.id != 0) {
        char text[255];
        sprintf(text, " %d ", crawler->node.id);
        show_highlight(text, CYAN, BLACK);

        crawler = crawler->next;
        if (crawler != NULL && crawler->node.id != 0) printf(" --- ");
    }
    endline();

    printf("   ⌊");
    show_repeated("_", lineSize);
    printf("⌋");
    endline();

}

void stdeck_print_node(StudentsDeckNode src, char *title) {
    endline();

    show_text(title, NORMAL);
    char text[255];
    sprintf(text, "{ id: %d, pos: %d, name: %s }", src.id, src.pos, src.name);
    show_highlight(text, WHITE, BLACK);

    endline();
}

void stdeck_print_element(StudentsDeckElement *src, char *title) {
    endline();
    show_text_ln(title, NORMAL);

    char text[255];
    sprintf(text, "    node.value: %d ", src->node.id);
    show_text(text, BLUE);

    if (src->next != NULL) {
        sprintf(text, "    next.node.id: %d ", src->next->node.id);
        show_text(text, BLUE);
    } else {
        show_text("    next: NULL ", BLUE);
    }

    if (src->previous != NULL) {
        sprintf(text, "    previous.node.value: %d ", src->previous->node.id);
        show_text(text, BLUE);
    } else {
        show_text("    previous: NULL ", BLUE);
    }

    endline();
}

void stdeck_print_as_stack(StudentsDeck *src) {
    endline();
    StudentsDeckElement *crawler = src->head;
    int lineSize = src->len * 8 + src->len;

    show_highlight_ln(" HEAD ", BLUE, BLACK);

    if (stdeck_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    char text[255];
    int next, previous;
    next = (crawler->next != NULL) ? crawler->next->node.id : 0;
    previous = (crawler->previous != NULL) ? crawler->previous->node.id : 0;

    sprintf(text, " [%2d] (next: %2d) (previous: %2d)", crawler->node.id, next, previous);
    show_text(text, CYAN);
    endline();

    crawler = crawler->next;
    while (crawler != NULL && crawler->node.id != 0) {

        next = (crawler->next != NULL) ? crawler->next->node.id : 0;
        previous = (crawler->previous != NULL) ? crawler->previous->node.id : 0;

        sprintf(text, " [%2d] (next: %2d) (previous: %2d)", crawler->node.id, next, previous);
        show_text(text, CYAN);

        crawler = crawler->next;
        endline();
    }
    endline();

    endline();
}