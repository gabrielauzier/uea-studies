/*
 * Polynomial
 *
 * Implementation using Dynamic Linked List (dyll)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polynomial.h"
#include "../utils/show.h"

typedef struct PolynomialNode {
    int exp;
    int coefficient;
} PolynomialNode ;

typedef struct PolynomialElement {
    PolynomialNode node;
    PolynomialElement *next;
} PolynomialElement;

typedef struct Polynomial {
    PolynomialElement *head;
} Polynomial;

Polynomial * create_polynomial() {
    Polynomial *src = malloc(sizeof (Polynomial));
    src->head = NULL;
    return src;
}

PolynomialNode * create_polynomial_node(int coefficient, int exp) {
    PolynomialNode *src = malloc(sizeof(PolynomialNode));
    src->coefficient = coefficient;
    src->exp = exp;
    return src;
};

int get_polynomial_length(Polynomial *src) {
    int len = 0;
    PolynomialElement *crawler = src->head;
    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }
    return len;
};

void print_polynomial(char *title, Polynomial *src) {
    PolynomialElement *crawler = src->head;
    show_subtitle(title);
    while(crawler != NULL) {
        show_subtitle("PolynomialNode");
        show_attr_int("node.coefficient", crawler->node.coefficient);
        show_attr_int("node.exp", crawler->node.exp);

        crawler = crawler->next;
    }
};

void print_beauty_polynomial(char *title, Polynomial *src) {
    PolynomialElement *crawler = src->head;

    show_text_ln(title, BLUE);

    while(crawler != NULL) {
        show_start(BLUE, BLACK);
        printf(" %dx^(%d) ", crawler->node.coefficient, crawler->node.exp);
        show_close();

        crawler = crawler->next;

        if (crawler != NULL) printf(" + ");
    }

    endline();
    endline();
};

/* sorted by exp */
PolynomialElement * find_polynomial_element_and_previous(Polynomial *src, int newExp, PolynomialElement **previous) {
    *previous = NULL;
    PolynomialElement *crawler = src->head;

    /* decreasing order (>) */
    while (crawler != NULL && crawler->node.exp > newExp) {
        *previous = crawler;
        crawler = crawler->next;
    }

    return (crawler != NULL && crawler->node.exp == newExp) ? crawler : NULL;
};

int insert_polynomial_node(Polynomial *src, PolynomialNode *newNode) {
    int newExp = newNode->exp;
    PolynomialElement *previous;
    PolynomialElement *crawler;

    crawler = find_polynomial_element_and_previous(src, newExp, &previous);
    if (crawler != NULL) return 0;

    crawler = malloc(sizeof (PolynomialElement));
    crawler->node = *newNode;
    if (previous == NULL) {
        crawler->next = src->head;
        src->head = crawler;
    } else {
        crawler->next = previous->next;
        previous->next = crawler;
    }

    return 1;
};

Polynomial * sum_polynomials(Polynomial *src1, Polynomial *src2) {
    Polynomial * result = create_polynomial();

    PolynomialElement *crawler_1 = src1->head;
    PolynomialElement *crawler_2 = src2->head;

    while (crawler_1 != NULL && crawler_2 != NULL) {
        if (crawler_1->node.exp == crawler_2->node.exp) {
            int exp = crawler_1->node.exp;
            int coefficient = crawler_1->node.coefficient + crawler_2->node.coefficient;

            PolynomialNode *node = create_polynomial_node(coefficient, exp);
            insert_polynomial_node(result, node);

            crawler_1 = crawler_1->next;
            crawler_2 = crawler_2->next;
            continue;
        } else if (crawler_1->node.exp > crawler_2->node.exp) {
            int exp = crawler_1->node.exp;
            int coefficient = crawler_1->node.coefficient;

            PolynomialNode *node = create_polynomial_node(coefficient, exp);
            insert_polynomial_node(result, node);

            crawler_1 = crawler_1->next;
            continue;
        } else {
            int exp = crawler_2->node.exp;
            int coefficient = crawler_2->node.coefficient;

            PolynomialNode *node = create_polynomial_node(coefficient, exp);
            insert_polynomial_node(result, node);

            crawler_2 = crawler_2->next;
            continue;
        }
    }

    return result;
};