/* Dynamic Linked List (dyll) */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct DyllElement DyllElement;

typedef struct DynamicLinkedList DynamicLinkedList;

DynamicLinkedList * dyll_create_linked_list();
Node * dyll_create_node(int value);

void dyll_init_list(DynamicLinkedList *src);
int dyll_get_valid_elements(DynamicLinkedList *src);

void dyll_print_list(DynamicLinkedList *src);
void dyll_print_element(DyllElement *src);

DyllElement * dyll_find_one(DynamicLinkedList *src, int valueTarget);
DyllElement * dyll_find_element_and_previous(DynamicLinkedList *src, int newRegistration, DyllElement **previous);

int dyll_insert_node(DynamicLinkedList *src, Node *newNode);
int dyll_delete_node(DynamicLinkedList *src, int valueTarget);
void dll_restart_list(DynamicLinkedList *src);