#include <stdlib.h>
#include <stdio.h>

#include "complex-numbers.h"

 struct ComplexNumber {
    float x;
    float y;
    string algebraic;
};

void show_imaginary_number(ComplexNumber *src, string title) {
    printf("\n___________________________________\n");
    printf("%s = %s", title, src->algebraic);
}

ComplexNumber * create_complex_number(float real, float imag) {
    ComplexNumber *num = malloc(sizeof(ComplexNumber));

    num->x = real;
    num->y = imag;

    char *target = num->algebraic;

    target += sprintf(target, "%.1f + ", real);
    target += sprintf(target, "%.1fi", imag);

    return num;
}

void delete_imaginary_number(ComplexNumber *src) {
    free(src);
}

ComplexNumber * sum_complex_numbers(ComplexNumber *num1, ComplexNumber *num2) {
    return create_complex_number(num1->x + num2->x, num1->y + num2->y);
}

ComplexNumber * subtract_complex_numbers(ComplexNumber *num1, ComplexNumber *num2) {
    return create_complex_number(num1->x - num2->x, num1->y - num2->y);
}

ComplexNumber * multiply_complex_numbers(ComplexNumber *num1, ComplexNumber *num2) {
    const float a = num1->x, b = num1->y;
    const float c = num2->x, d = num2->y;

    const float real = a * c - b * d;
    const float imag = a * d + b * c;

    return create_complex_number(real, imag);
}

ComplexNumber * divide_complex_numbers(ComplexNumber *num1, ComplexNumber *num2) {
    const float a = num1->x, b = num1->y;
    const float c = num2->x, d = num2->y;

    const float real = (a * c + b * d) / (c * c + d * d);
    const float imag = (c * b - a * d) / (c * c + d * d);

    return create_complex_number(real, imag);
}

ComplexNumber * calculate(ComplexNumber *num1, ComplexNumber *num2, ComplexNumberOperations operation) {
    switch (operation) {
        case sum:
            return sum_complex_numbers(num1, num2);
        case subtract:
            return subtract_complex_numbers(num1, num2);
        case multiply:
            return multiply_complex_numbers(num1, num2);
        case divide:
            return divide_complex_numbers(num1, num2);
    }
}