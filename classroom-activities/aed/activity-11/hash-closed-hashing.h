
/*
 * Simple hash (sh)
 *
 * Implemented using hash table with open addressing (without linked lists)
 *
 * */

#define MAX_CHAR 255
#include <stdbool.h>

typedef int (hch_table_function) (const int, const int, const int);
typedef struct hch_element hch_element;
typedef struct hch_table hch_table;

hch_table * hch_table_create(int size, hch_table_function *hf);
void hch_table_destroy(hch_table *src);
void hch_table_delete(hch_table *src, int key);
bool hch_table_insert(hch_table *src, int key, int value);

void hch_table_print(hch_table *src, char *title);
hch_element * hch_table_lookup(hch_table *src, int code);
void hch_table_use_double_hash(hch_table *src, hch_table_function *hf);

void hch_table_fill(hch_table *src, const int *values, int values_len);

