/* Simple Dynamic Stack (artexpstack) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 25

#include "arithmetic-expression-stack.h"
#include "../utils/show.h"

ArithmeticExpressionStack * artexpstack_create_stack() {
    ArithmeticExpressionStack *src = malloc(sizeof (ArithmeticExpressionStack));
    src->top = NULL;
    return src;
}

ArithmeticExpressionStack * artexpstack_create_stack_by_exp(char *exp) {
    ArithmeticExpressionStack *src = malloc(sizeof (ArithmeticExpressionStack));

    for (int i = 0; i < strlen(exp); i++) {
        artexpstack_push_node(src, *artexpstack_create_node(exp[i] - '0', exp[i]));
    }

    return src;
}

ArithmeticExpressionNode * artexpstack_create_node(int value, char valueChar) {
    ArithmeticExpressionNode *src = malloc(sizeof (ArithmeticExpressionNode));
    src->value = value;
    src->valueChar = valueChar;
    return src;
}

void artexpstack_push_node(ArithmeticExpressionStack *src, ArithmeticExpressionNode newNode) {
    ArithmeticExpressionElement *newElement = malloc(sizeof (ArithmeticExpressionElement));
    newElement->node = newNode;
    newElement->next = src->top;
    src->top = newElement;
}

void artexpstack_push_node_value(ArithmeticExpressionStack *src, ArithmeticExpressionNode newNode) {
    ArithmeticExpressionElement *newElement = malloc(sizeof (ArithmeticExpressionElement));
    newElement->node = newNode;
    newElement->next = src->top;
    src->top = newElement;
}

ArithmeticExpressionNode artexpstack_pop_node(ArithmeticExpressionStack *src) {
    ArithmeticExpressionElement *top = src->top;
    ArithmeticExpressionNode topNode = top->node;
    src->top = src->top->next;
    free(top);
    return topNode;
}

ArithmeticExpressionNode artexpstack_peek_node(ArithmeticExpressionStack *src) {
    return src->top->node;
}

int artexpstack_is_empty(ArithmeticExpressionStack *src) {
    return (src->top == NULL) ? 1 : 0;
}

void artexpstack_print_stack(ArithmeticExpressionStack *src) {
    endline();
    endline();

    ArithmeticExpressionElement *crawler = src->top;
    char text[255];

    show_start(MAGENTA, BLACK);
    show_text_align_center("TOP", MAX_LINE_SIZE);
    show_close();
    endline();
    endline();

    if (artexpstack_is_empty(src)) {
        show_start(BLUE, BLACK);
        sprintf(text, "NULL");
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();
        endline();
    }

    while (crawler != NULL) {
        show_start(BLUE, BLACK);
        sprintf(text, "node.value: %d", crawler->node.value);
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();

        show_start(BLUE, BLACK);
        sprintf(text, "node.valueChar: %c", crawler->node.valueChar);
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();

        endline();
        crawler = crawler->next;
    }

    show_close();
}

void artexpstack_print_node(ArithmeticExpressionNode node) {
    endline();
    char text[255];
    show_start(BLUE, BLACK);
    sprintf(text, "value: %d", node.value);
    show_text_align_center(text, MAX_LINE_SIZE);

    show_close();
    endline();
    endline();
}