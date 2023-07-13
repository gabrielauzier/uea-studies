#include <stdlib.h>

#include "hash-separate-chaining.h"
#include "../utils/show.h"

#define array_len(x) (sizeof(x) / sizeof((x)[0]))

void init_main() {
    init_show();
}

int hash(const char *key) {
    int key_value = atoi(key);
    return (2 * key_value + 5);
}

void execute_hash_separate_chaining() {
    show_header("Exercise - Hash with separate chaining", MAGENTA);

    int table_size;
    int values[] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };

    hsc_table *table;

    table_size = 9;
    table= hsc_table_create(table_size, hash);
    hsc_table_fill_numbers(table, values, array_len(values));
    hsc_table_print(table, "Table 1 - len 9");
    hsc_table_destroy(table);

    table_size = 11;
    table= hsc_table_create(table_size, hash);
    hsc_table_fill_numbers(table, values, array_len(values));
    hsc_table_print(table, "Table 2 - len 11");
    hsc_table_destroy(table);
}

int main() {
    init_main();
    execute_hash_separate_chaining();
    return 0;
}
