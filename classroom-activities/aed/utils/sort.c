#include "sort.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort_array(int *array, int length) {
    int min;

    for (int i = 0; i < length - 1; i++) {
        min = i;

        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min]) min = j;
        }

        if (min != i)
            swap(&array[min], &array[i]);
    }
}