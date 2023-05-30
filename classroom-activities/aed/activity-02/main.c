#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "class.h"

#include "../utils/show.h"

void test_sequential_search(List *list);
void test_binary_search(List *list);
void test_get_lower(List *list);
void test_get_greater(List *list);
void test_get_sum(List *list);
void test_get_prod(List *list);

void exercise01() {
    List *list = create_list(10);

    fill_list(list);
    print_list_iterative(list);

    sort_list(list);
    print_list_iterative(list);

    test_sequential_search(list);
    test_binary_search(list);
    test_get_lower(list);
    test_get_greater(list);
    test_get_sum(list);
    test_get_prod(list);

    free_list(list);
}

void exercise02() {
    Student *std = create_student(1,"Gabriel", 19, 9.32);
    Student *std2 = create_student(2,"Rafael", 3, 1.2);

    show_student(std);
    show_student(std2);

    Class *class = create_class(10);

    insert_student(class, std);
    insert_student(class, std2);

    show_class(class);

    Student *result = find_student_by_id_v1(class, 2);
    show_student(result);
}

void _config_main() {
    init_show();
    srand(time(NULL));
}

int main() {
    _config_main();

    exercise01();
    exercise02();

    end();
}

void test_sequential_search(List *list) {
    title("Test Suite - Sequential search iterative ");

    int i = 0;
    int search_response;
    int tries[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, -1 };

    while (tries[i] != -1) {
        search_response = sequential_search_list(list, tries[i]);

        printf("\nTest %d: ", i + 1);

        if (search_response == -1) {
            printf("Target %d not found. ", tries[i]);
            i++;
            continue;
        }

        printf("Target %d found at index %d. ", tries[i], search_response);
        i++;
    }
}

void test_binary_search(List *list) {
    int i;
    int search_response;
    int tries[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, -1 };

    title("Test Suite - Binary search iterative ");

    i = 0;
    while (tries[i] != -1) {
        search_response = binary_search_list_iterative(list, tries[i]);

        printf("\nTest %d: ", i + 1);

        if (search_response == -1) {
            printf("Target %d not found. ", tries[i]);
            i++;
            continue;
        }

        printf("Target %d found at index %d. ", tries[i], search_response);
        i++;
    }

    title("Test Suite - Binary search recursive ");

    i = 0;
    while (tries[i] != -1) {
        search_response = binary_search_list_recursive(list, tries[i], 0, list->length - 1);

        printf("\nTest %d: ", i + 1);

        if (search_response == -1) {
            printf("Target %d not found. ", tries[i]);
            i++;
            continue;
        }

        printf("Target %d found at index %d. ", tries[i], search_response);
        i++;
    }
}

void test_get_lower(List *list) {
    title("Test Suite - Get lower ");
    int result;

    result = get_lower_list_iterative(list);
    printf("\nLower (iteratively) = %d", result);

    result = get_lower_list_recursive(list, list->values[0], 0);
    printf("\nLower (recursively) = %d", result);
}

void test_get_greater(List *list) {
    title("Test Suite - Get greater ");
    int result;

    result = get_greater_list_iterative(list);
    printf("\nGreater (iteratively) = %d", result);

    result = get_greater_list_recursive(list, list->values[0], 0);
    printf("\nGreater (recursively) = %d", result);
}

void test_get_sum(List *list) {
    title("Test Suite - Get sum ");
    int result;

    result = get_sum_list_iterative(list);
    printf("\nSum (iteratively) = %d", result);

    result = get_sum_list_recursive(list, 0, 0);
    printf("\nSum (recursively) = %d", result);
}

void test_get_prod(List *list) {
    title("Test Suite - Get prod ");
    long long int result;

    result = get_prod_list_iterative(list);
    printf("\nProd (iteratively) = %lld", result);

    result = get_prod_list_recursive(list, 1, 0);
    printf("\nProd (recursively) = %lld", result);
}
