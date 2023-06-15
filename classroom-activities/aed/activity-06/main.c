#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "../utils/show.h"
#include "polynomial.h"
#include "doubled-linked-list.h"

void init_main_() {
    init_show();

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) printf("Running at %s", cwd);
    else perror("getcwd() error");

    endline();
}

void exercise01() {
    show_header("Exercise 01 - Doubled Linked List", MAGENTA);

    DoubledLinkedList *list = dobll_create_linked_list();
    DoubledLinkedList *sorted_list = dobll_create_linked_list();

    DobllNode *a = dobll_create_node(10);
    DobllNode *b = dobll_create_node(33);
    DobllNode *c = dobll_create_node(5);

    dobll_insert_node_without_sort(list, a);
    dobll_insert_node_without_sort(list, b);
    dobll_insert_node_without_sort(list, c);

    dobll_insert_value(list, 32);
    dobll_insert_value(list, 45123);
    dobll_insert_value(list, 353);
    dobll_insert_value(list, 6443);
    dobll_insert_value(list, 546);

    dobll_print_list_beauty("Original List: ", list);
    dobll_print_list_beauty("Sorted List: ", sorted_list);

    dobll_shift_all_elements(list, sorted_list);

    dobll_print_list_beauty("Sorted List: ", sorted_list);
    dobll_print_list_beauty("Original List: ", list);

    endline();
}

void exercise02() {
    show_header("Exercise 02 - Polynomials", BLUE);

    Polynomial *polynomial_1 = create_polynomial();
    PolynomialNode *a1 = create_polynomial_node(1, 3);
    PolynomialNode *b1 = create_polynomial_node(2, 2);
    PolynomialNode *c1 = create_polynomial_node(4, 1);
    PolynomialNode *d1 = create_polynomial_node(7, 0);

    insert_polynomial_node(polynomial_1, a1);
    insert_polynomial_node(polynomial_1, b1);
    insert_polynomial_node(polynomial_1, c1);
    insert_polynomial_node(polynomial_1, d1);

    Polynomial *polynomial_2 = create_polynomial();
    PolynomialNode *a2 = create_polynomial_node(4, 3);
    PolynomialNode *c2 = create_polynomial_node(2, 1);
    PolynomialNode *d2 = create_polynomial_node(3, 0);
    PolynomialNode *e2 = create_polynomial_node(2, 2);
    PolynomialNode *f2 = create_polynomial_node(3, 7);
    PolynomialNode *g2 = create_polynomial_node(5, 5);

    insert_polynomial_node(polynomial_2, a2);
    insert_polynomial_node(polynomial_2, d2);
    insert_polynomial_node(polynomial_2, c2);
    insert_polynomial_node(polynomial_2, e2);
    insert_polynomial_node(polynomial_2, f2);
    insert_polynomial_node(polynomial_2, g2);

    print_beauty_polynomial("Polynomial 1", polynomial_1);
    print_beauty_polynomial("Polynomial 2", polynomial_2);

    Polynomial *result = sum_polynomials(polynomial_1, polynomial_2);
    print_beauty_polynomial("Polynomial Sum Result", result);

}

int main() {
    init_main_();

    exercise01();
    exercise02();
    return 0;
}