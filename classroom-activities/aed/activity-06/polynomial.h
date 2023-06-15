/* Dynamic Linked List (dyll) */

#include <stdio.h>
#include <stdlib.h>

typedef struct PolynomialNode PolynomialNode;

typedef struct PolynomialElement PolynomialElement;

typedef struct Polynomial Polynomial;

Polynomial * create_polynomial();
PolynomialNode * create_polynomial_node(int coefficient, int exp);

Polynomial * sum_polynomials(Polynomial *src1, Polynomial *src2);

void print_polynomial(char *str, Polynomial *src);
void print_beauty_polynomial(char *title, Polynomial *src);

PolynomialElement * find_polynomial_element_and_previous(Polynomial *src, int newExp, PolynomialElement **previous);

int insert_polynomial_node(Polynomial *src, PolynomialNode *newPolynomialNode);
