#include <stdio.h>
#include <stdlib.h>

#include "static-linked-list.h"

typedef struct StaticLinkedList {

} StaticLinkedList;

StaticLinkedList * create_sll();

void free_sll(StaticLinkedList *sll);

void init_sll(StaticLinkedList *sll);

int get_valid_elements_on_sll(StaticLinkedList *sll);

int is_empty_sll(StaticLinkedList *sll);

void show_sll(StaticLinkedList *sll);

void insert_element_sll(StaticLinkedList *sll);

void delete_element_sll(StaticLinkedList *sll, int value);

void update_element_sll(StaticLinkedList *sll, int value);


