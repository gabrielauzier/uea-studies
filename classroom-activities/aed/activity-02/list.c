#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "../utils/random.h"
#include "../utils/sort.h"

#define warn(s) (printf("\nErr: %s", s))

List * create_list(int length) {
    List * output = malloc(sizeof (List));

    output->maxLength = length;
    output->length = 0;
    output->values = malloc(sizeof (int) * length);

    return output;
}

void sort_list(List *list) {
    selection_sort_array(list->values, list->length);
}

void insert(List *list, int value) {
    int len = list->length;

    if (len == list->maxLength) {
        warn("List full");
        return;
    }

    list->values[len] = value;
    list->length++;
}

void fill_list(List *list) {
    for (int i = list->length; i < list->maxLength; i++) {
        const int value = generate_random_int(100);
        insert(list, value);
    }

    list->length = list->maxLength;
}

void fill_list_ord(List *list) {
    insert(list, generate_random_int(10));

    for (int i = 1, k = 20; i < list->maxLength; i++, k+=10) {
        int value;
        do {
            value = generate_random_int(k);
            if (value <= list->values[i - 1]) continue;

            insert(list, value);
        } while(value <= list->values[i - 1]);
    }
}

void print_list_iterative(List *list) {
    if (list->length == 0) {
        warn("List empty");
        return;
    }

    printf("\nList = [");

    for (int i = 0; i < list->maxLength; i++) {
        if (i == list->length - 1) {
            printf("%d]", list->values[i]);
            break;
        }

        printf("%d, ", list->values[i]);
    }
}

void print_list_recursive(List *list, int index) {
    if (list->length == 0) {
        warn("List empty");
        return;
    }

    if (index == list->maxLength) return;

    printf("%d ", list->values[index]);

    print_list_recursive(list, ++index);
}

int sequential_search_list(List *list, int target) {
    for (int i = 0; i < list->length; i++) {
        if (list->values[i] == target) {
            return i;
        }
    }

    return -1;
}

int binary_search_list_iterative(List *list, int target) {
    int low = 0;
    int high = list->length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int value = list->values[mid];

        if (value == target) return mid;

        if (value > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int binary_search_list_recursive(List *list, int target, int low, int high) {
    int mid = low + (high - low) / 2;
    int value = list->values[mid];

    if (value == target) return mid;

    if (low <= high) {
        return value > target ?
            binary_search_list_recursive(list, target, low, mid - 1) :
            binary_search_list_recursive(list, target, mid + 1, high);
    }

    return -1;
}

int get_lower_list_iterative(List *list) {
    int lower = list->values[0];

    for (int i = 0; i < list->length; i++) {
        if (list->values[i] < lower) {
            lower = list->values[i];
        }
    }

    return lower;
}

int get_lower_list_recursive(List *list, int lower, int index) {
    if (index == list->length) return lower;

    if (list->values[index] < lower) lower = list->values[index];

    return get_lower_list_recursive(list, lower, ++index);
}

int get_greater_list_iterative(List *list) {
    int greater = list->values[0];

    for (int i = 0; i < list->length; i++) {
        if (list->values[i] > greater) {
            greater = list->values[i];
        }
    }

    return greater;
}

int get_greater_list_recursive(List *list, int greater, int index) {
    if (index == list->length) return greater;

    if (list->values[index] > greater) greater = list->values[index];

    return get_greater_list_recursive(list, greater, ++index);
}

int get_sum_list_iterative(List *list) {
    int sum = 0;

    for (int i = 0; i < list->length; i++) {
        sum += list->values[i];
    }

    return sum;
}

int get_sum_list_recursive(List *list, int sum, int index) {
    if (index == list->length) return sum;

    sum += list->values[index];

    return get_sum_list_recursive(list, sum, ++index);
}

long long int get_prod_list_iterative(List *list) {
    long long int prod = 1;

    for (int i = 0; i < list->length; i++) {
        prod *= list->values[i];
    }

    return prod;
}

long long int get_prod_list_recursive(List *list, long long int prod, int index) {
    if (index == list->length) return prod;

    prod *= list->values[index];

    return get_prod_list_recursive(list, prod, ++index);
}

void free_list(List *list) {
    free(list->values);
    free(list);
}