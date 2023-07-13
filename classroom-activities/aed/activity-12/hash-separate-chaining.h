/*
 * Hash with Separate Chaining (hsc)
 *
 * Implemented using hash + linked list to resolve conflicts
 *
 * */

#include <stdbool.h>

typedef struct hsc_entry hsc_entry;
typedef int (hsc_hash_function) (const char*);

typedef struct hsc_table hsc_table;

hsc_table * hsc_table_create(int size, hsc_hash_function *hf);
void hsc_table_destroy(hsc_table *table);
void hsc_table_print(hsc_table *table, const char *title);
bool hsc_table_insert(hsc_table *table, const char *key, void *obj);
void * hsc_table_lookup(hsc_table *table, const char *key);
void * hsc_table_delete(hsc_table *table, const char *key);

void hsc_table_fill_numbers(hsc_table *table, const int *values, int values_len);
