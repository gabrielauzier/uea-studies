/*
 * Hash Open Addressing or Hash with Closed Hashing (hch)
 *
 * Implemented using hash table with open addressing (without linked lists)
 *
 * */

#define MAX_SIZE 101
#define MAX_CHAR 255

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../utils/show.h"
#include "hash-closed-hashing.h"

typedef struct hch_element {
    int key;
    int value;
} hch_element;

typedef struct hch_table {
    hch_table_function *hash;
    hch_table_function *double_hash;

    hch_element **elements;
    int size;
    int collisions;
} hch_table;

hch_table * hch_table_create(int size, hch_table_function *hf) {
    hch_table *new = malloc(sizeof (*new));
    new->size = size;
    new->hash = hf;
    new->double_hash = NULL;
    new->collisions = 0;

    /* zeros out the memory */
    new->elements = calloc(sizeof (hch_element*), new->size);
    return new;
}

void hch_table_destroy(hch_table *src) {
    free(src->elements);
    free(src);
}

void hch_table_use_double_hash(hch_table *src, hch_table_function *hf) {
    src->double_hash = hf;
}

bool hch_table_try_insert(hch_table *src, const int i, const int key, const int value, bool use_double_hash) {
    int index;

    index = src->hash(key, i, src->size) % src->size;
    if (use_double_hash == true)
        index = (src->hash(key, i, src->size) + i * src->double_hash(key, i, src->size)) % src->size;

    if (src->elements[index] != NULL) {
        src->collisions++;
        return false;
    }

    hch_element *e = malloc(sizeof(hch_element));
    e->key = key;
    e->value = value;
    src->elements[index] = e;
    return true;
}

bool hch_table_insert(hch_table *src, int key, int value) {
    int i = 0;
    bool inserted = false;

    inserted = hch_table_try_insert(src, i, key, value, false);

    while (inserted == false && i < src->size) {
        i++;
        if (src->double_hash != NULL)
            inserted = hch_table_try_insert(src, i, key, value, true);
        else
            inserted = hch_table_try_insert(src, i, key, value, false);
    }

    return inserted;
}

void hch_table_print(hch_table *src, char *title) {
    show_start(BLACK, BLUE);
    printf("\n___________________\n");
    printf("%s", title);
    printf("\n___________________\n");
    for (int i = 0; i < src->size; i++) {
        show_start(BLACK, BLUE);
        if (src->elements[i] == NULL) {
            printf("[%03i] ---> ", i);
            show_text_ln("NULL", MAGENTA);
        } else {
            printf("[%03i] ---> %d\n", i, src->elements[i]->value);
        }
    }
    show_attr_int("Collisions", src->collisions);
    show_close();
    endline();
}

void hch_table_fill(hch_table *src, const int *values, int values_len) {
    for (int i = 0; i < values_len; i++) {
        int new_value = values[i];
        hch_table_insert(src, new_value, new_value);
    }
}
