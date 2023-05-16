#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cube.h"
#include "imaginary-numbers.h"

void exercise01() {
    Cube *cube = createCube(12);

    printf("Exercise 01:\n");

    showCube(cube);

    setCubeSide(cube, 2);
    showCube(cube);
}

void separate() {
    printf("\n###################################\n");
}

void exercise02() {
    ImaginaryNumber *num1 = create_imaginary_number(2, 3);
    ImaginaryNumber *num2 = create_imaginary_number(-4, 5);

    ImaginaryNumber *sumResult = calculate(num1, num2, sum);
    ImaginaryNumber *subResult = calculate(num1, num2, subtract);
    ImaginaryNumber *mutResult = calculate(num1, num2, multiply);

    show_imaginary_number(num1, "Num 1");
    show_imaginary_number(num2, "Num 2");

    show_imaginary_number(sumResult, "Sum result");
    show_imaginary_number(subResult, "Subtract result");
    show_imaginary_number(mutResult, "Multiply result");

    separate();

    delete_imaginary_number(num1);
    delete_imaginary_number(num2);
    delete_imaginary_number(sumResult);
}

int main() {
//    exercise01();
    exercise02();

    return 0;
}
