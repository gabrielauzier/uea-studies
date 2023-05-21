#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cube.h"
#include "complex-numbers.h"

#define separate() (printf("\n###################################\n"))

void exercise01() {
    Cube *cube = createCube(12);

    printf("Exercise 01:\n");

    showCube(cube);

    setCubeSide(cube, 2);
    showCube(cube);
}

void exercise02() {
    ComplexNumber *num1 = create_complex_number(3, 2);
    ComplexNumber *num2 = create_complex_number(0, 4);


    ComplexNumber *sumResult = calculate(num1, num2, sum);
    ComplexNumber *subResult = calculate(num1, num2, subtract);
    ComplexNumber *mutResult = calculate(num1, num2, multiply);
    ComplexNumber *divResult = calculate(num1, num2, divide);

    show_imaginary_number(num1, "Num 1");
    show_imaginary_number(num2, "Num 2");

    show_imaginary_number(sumResult, "Sum result");
    show_imaginary_number(subResult, "Subtract result");
    show_imaginary_number(mutResult, "Multiply result");
    show_imaginary_number(divResult, "Divide result");

    separate();

    delete_imaginary_number(num1);
    delete_imaginary_number(num2);
    delete_imaginary_number(sumResult);
    delete_imaginary_number(subResult);
    delete_imaginary_number(mutResult);
    delete_imaginary_number(divResult);
}

int main() {
    exercise01();
    exercise02();

    return 0;
}
