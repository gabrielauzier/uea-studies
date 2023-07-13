#include <stdlib.h>

#include "hash-closed-hashing.h"
#include "../utils/show.h"

#define array_len(x) (sizeof(x) / sizeof((x)[0]))

void init_main() {
    init_show();
}

/** linear polling hash */
int hch_table_v1(const int key, const int index, const int length) {
    int hash_value = (key + index);
    return hash_value;
}

/** quadratic polling 1.0 hash */
int hch_table_v2(const int key, const int index, const int length) {
    int hash_value = (key + index * index);
    return hash_value;
}

/** quadratic polling 2.0 hash */
int hch_table_v3(const int key, const int index, const int length) {
    int hash_value = (key + 2 * index + index * index);
    return hash_value;
}

/** double hash main hash */
int double_hash1(const int key, const int index, const int length) {
    return key;
}

/** double hash resolution hash */
int double_hash2(const int key, const int index, const int length) {
    return 7 - (key % 7);
}

void execute_hash_closed_hashing() {
    show_header("Exercise - Hash with open addressing (closed hashing)", BLUE);

    hch_table *table;

    int table_size = 11;
    int values[] = { 365, 112, 180, 213, 13, 27 };

    table = hch_table_create(table_size, hch_table_v1);
    hch_table_fill(table, values, array_len(values));
    hch_table_print(table, "Table v1");
    hch_table_destroy(table);

    table = hch_table_create(table_size, hch_table_v2);
    hch_table_fill(table, values, array_len(values));
    hch_table_print(table, "Table v2");
    hch_table_destroy(table);

    table = hch_table_create(table_size, hch_table_v3);
    hch_table_fill(table, values, array_len(values));
    hch_table_print(table, "Table v3");
    hch_table_destroy(table);

    table = hch_table_create(table_size, double_hash1);
    hch_table_use_double_hash(table, double_hash2);
    hch_table_fill(table, values, array_len(values));
    hch_table_print(table, "Table v4");
    hch_table_destroy(table);
}

int main() {
    init_main();
    execute_hash_closed_hashing();
    return 0;
}