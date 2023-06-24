/* Dynamic Linked List (dyll) */

#include <stdio.h>
#include <stdlib.h>

#include "../utils/show.h"
#include "dynamic-linked-list.h"

typedef struct Node {
    int value;
} Node;

typedef struct DyllElement {
    Node node;
    struct DyllElement *next;
} DyllElement;

typedef struct DynamicLinkedList {
    DyllElement *head;
} DynamicLinkedList;

DynamicLinkedList * dyll_create_linked_list() {
    DynamicLinkedList *src = malloc(sizeof (DynamicLinkedList));

    dyll_init_list(src);

    return src;
}

Node * dyll_create_node(int value) {
    Node *src = malloc(sizeof (Node));

    src->value = value;

    return src;
}

void dyll_init_list(DynamicLinkedList *src) {
    src->head = NULL;
}

int dyll_get_valid_elements(DynamicLinkedList *src) {
    int len = 0;
    DyllElement *crawler = src->head;

    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }

    return len;
}

void dyll_print_list(DynamicLinkedList *src) {
    DyllElement *crawler = src->head;

    show_title("Dynamic Linked List");

    while (crawler != NULL) {
        show_attr_int("node.value", crawler->node.value);

        crawler = crawler->next;
    }
}

void dyll_print_element(DyllElement *src) {
    show_title("Linked List DyllElement");

    show_attr_int("node.value", src->node.value);
    show_attr_int("next.value", src->next->node.value);
}

DyllElement * dyll_find_one(DynamicLinkedList *src, int valueTarget) {
    DyllElement *crawler = src->head;

    while (crawler != NULL) {
        if (crawler->node.value == valueTarget) return crawler;

        crawler = crawler->next;
    }

    return NULL;
}

DyllElement * dyll_find_element_and_previous(DynamicLinkedList *src, int newValue, DyllElement **previous) {
    *previous = NULL;

    DyllElement *crawler = src->head;

    while (crawler != NULL && crawler->node.value < newValue) {
        *previous = crawler;
        crawler = crawler->next;
    }

    if (crawler != NULL && crawler->node.value == newValue) return crawler;

    return NULL;
}

int dyll_insert_node(DynamicLinkedList *src, Node *newNode) {
    int newValue = newNode->value;
    DyllElement *previous;
    DyllElement *crawler;

    crawler = dyll_find_element_and_previous(src, newValue, &previous);

    if (crawler != NULL) return 0;

    crawler = malloc(sizeof (DyllElement));

    crawler->node = *newNode;

    if (previous == NULL) {
        crawler->next = src->head;
        src->head = crawler;
    } else {
        crawler->next = previous->next;
        previous->next = crawler;
    }

    return 1;
}

int dyll_delete_node(DynamicLinkedList *src, int valueTarget) {
    DyllElement *previous;
    DyllElement *crawler;

    crawler = dyll_find_element_and_previous(src, valueTarget, &previous);

    if (crawler == NULL) return 0;

    if (previous == NULL) {
        src->head = crawler->next;
    } else {
        previous->next = crawler->next;
    }

    free(crawler);
    return 1;
}

void dyll_restart_list(DynamicLinkedList *src) {
    DyllElement *crawler = src->head;

    while (crawler != NULL) {
        DyllElement *target = crawler;
        crawler = crawler->next;

        free(target);
    }

    src->head = NULL;
}