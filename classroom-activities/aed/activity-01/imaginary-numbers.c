#include <stdlib.h>
#include <stdio.h>

#include "imaginary-numbers.h"

 struct ImaginaryNumber {
    float x;
    float y;
    string algebraic;
};

void show_imaginary_number(ImaginaryNumber *src, string title) {
    printf("\n___________________________________\n");
    printf("%s = %s", title, src->algebraic);
}

ImaginaryNumber * create_imaginary_number(float real, float imag) {
    ImaginaryNumber *num = malloc(sizeof(ImaginaryNumber));

    num->x = real;
    num->y = imag;

    char *target = num->algebraic;

    target += sprintf(target, "%.0f + ", real);
    target += sprintf(target, "%.0fi", imag);

    return num;
}

void delete_imaginary_number(ImaginaryNumber *src) {
    free(src);
}

ImaginaryNumber * sum_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2) {
    return create_imaginary_number(num1->x + num2->x, num1->y + num2->y);
}

ImaginaryNumber * subtract_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2) {
    return create_imaginary_number(num1->x - num2->x, num1->y - num2->y);
}

ImaginaryNumber * multiply_imaginary_numbers(ImaginaryNumber *num1, ImaginaryNumber *num2) {
    const float a = num1->x, b = num1->y;
    const float c = num2->x, d = num2->y;

    const float real = a * c - b * d;
    const float imag = a * d + b * c;

    return create_imaginary_number(real, imag);
}

ImaginaryNumber * calculate(ImaginaryNumber *num1, ImaginaryNumber *num2, ImaginaryNumberOperations operation) {
    switch (operation) {
        case sum:
            return sum_imaginary_numbers(num1, num2);
        case subtract:
            return subtract_imaginary_numbers(num1, num2);
        case multiply:
            return multiply_imaginary_numbers(num1, num2);
    }
}