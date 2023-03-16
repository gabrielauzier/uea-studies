#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float * create_float_array(int tam) {
    return (float *) malloc(sizeof (float) * tam);
}

void scan(float * src, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%f", &src[i]);
    }
}

float calculate_average(float * src, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += src[i];
    }

    float avg = sum / (1.0 * n);
    printf("\naverage = %.2f", avg);

    return avg;
}

float calculate_standard_deviation(float * src, int n) {
    const float average = calculate_average(src, n);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(src[i] - average, 2);
    }
    return sqrt(sum / (1.0 * n));
}

int main() {
    int students = 5;

    float * grades = create_float_array(students);

    scan(grades, students);

    const float dev = calculate_standard_deviation(grades, students);

    printf("\nstandard deviation = %.2f", dev);

    free(grades);

    return 0;
}