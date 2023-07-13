/*
 * Hash with Separate Chaining (hsc)
 *
 * Implemented using hash + linked list to resolve conflicts
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../utils/show.h"
#include "hash-separate-chaining.h"

typedef struct hsc_entry {
    char *key;
    void *object;
    struct hsc_entry *next;
} hsc_entry;

typedef struct hsc_table {
    int size;
    hsc_hash_function *hash;
    hsc_entry **elements;
}  hsc_table;

hsc_table * hsc_table_create(int size, hsc_hash_function *hf) {
    hsc_table *new = malloc(sizeof (hsc_table));
    new->size = size;
    new->hash = hf;
    new->elements = calloc(sizeof (hsc_entry*), new->size);
    return new;
}

void hsc_table_destroy(hsc_table *table) {
    free(table->elements);
    free(table);
}

void hsc_table_print(hsc_table *table, const char *title) {
    show_start(NORMAL, MAGENTA);
    printf("\n___________________\n");
    printf("%s", title);
    printf("\n___________________\n");

    for (int i = 0; i < table->size; i++) {
        if (table->elements[i] == NULL) {
            printf("[%02i] --> ", i);
            show_text_ln("NULL", BLUE);
            show_start(NORMAL, MAGENTA);
        } else {
            printf("[%02i] --> ", i);
            hsc_entry *tmp = table->elements[i];
            while (tmp != NULL) {
                printf("%-2s", tmp->key);
                tmp = tmp->next;
                if (tmp != NULL)
                    printf(" --> ");
            }
            endline();
        }
    }
    show_close();
    endline();
}

int hsc_table_index(hsc_table *table, const char *key) {
    int index = table->hash(key) % table->size;
    return index;
}

bool hsc_table_insert(hsc_table *table, const char *key, void *obj) {
    if (key == NULL || table == NULL) return false;
    int index = hsc_table_index(table, key);

    /* no duplicates */
    if (hsc_table_lookup(table, key) != NULL) return false;

    /* create a new entry */
    hsc_entry *e = malloc(sizeof (*e));
    e->object = obj;
    e->key = malloc(strlen(key) + 1);
    strcpy(e->key, key);

    /* insert entry */
    e->next = table->elements[index];
    table->elements[index] = e;
    return true;
}

void hsc_table_fill_numbers(hsc_table *table, const int *values, int values_len) {
    for (int i = 0; i < values_len; i++) {
        char str[11];
        sprintf(str, "%d", values[i]);
        hsc_table_insert(table, str, str);
    }
}

void * hsc_table_lookup(hsc_table *table, const char *key) {
    if (key == NULL || table == NULL) return false;
    int index = hsc_table_index(table, key);

    hsc_entry *tmp = table->elements[index];
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    return tmp->object;
}

void * hsc_table_delete(hsc_table *table, const char *key) {
    if (key == NULL || table == NULL) return false;
    int index = hsc_table_index(table, key);

    hsc_entry *tmp = table->elements[index];
    hsc_entry *previous = NULL;
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
        previous = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (previous == NULL) {
        /* deleting at the head of the list */
        table->elements[index] = tmp->next;
    } else {
        /* deleting somewhere that is not the head */
        previous->next = tmp->next;
    }
    void *result = tmp->object;
    free(tmp);
    return result;
}