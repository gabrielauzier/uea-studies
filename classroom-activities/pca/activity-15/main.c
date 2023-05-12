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
    return sum / (1.0 * n);
}

float calculate_standard_deviation(float * src, int n) {
    const float average = calculate_average(src, n);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(src[i] - average, 2);
    }
    return sqrt(sum / (1.0 * n));
}

void set_values(int n, float * src, float * avg, float * dev) {
    *avg = calculate_average(src, n);
    *dev = calculate_standard_deviation(src, n);
}

int main() {
    int students = 5;

    float * grades = create_float_array(students);

    scan(grades, students);

    float avg, dev;

    set_values(students, grades, &avg, &dev);

    printf("\ntotal average = %.2f", avg);
    printf("\nstandard deviation = %.2f", dev);

    free(grades);

    return 0;
}