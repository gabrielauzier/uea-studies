#include <stdio.h>

#define MAX 10

typedef float FloatVector[MAX];
typedef int IntVector[MAX];

void print_vector(float *Crawler, float *End) {
    printf("Vector Initial Address [%p] \n", Crawler);
    while (Crawler <= End) {
        printf("%22.2f [%u]\n", *Crawler, Crawler);
        Crawler++;
    }
    puts("");
}

void exercise01() {
    FloatVector vector1 = {14.2, 32.42, 24, 324.03 };
    FloatVector vector2 = {132, 14.422, 432.2, 43.55, 134.4, 5163.0};
    FloatVector vector3 = {1, 2, 3, 4, 5, 6, 7, 8, 1992.4};

    print_vector(vector1, &vector1[3]);
    print_vector(&vector1[2], &vector1[3]);

    print_vector(vector2, &vector2[5]);
    print_vector(&vector2[3], &vector2[5]);

    print_vector(vector3, &vector3[8]);
    print_vector(&vector3[5], &vector3[8]);
}

int * find_one(int *Crawler, int *End, int target) {
    while (Crawler <= End) {
        if (*Crawler == target) {
            return Crawler;
        }
        Crawler++;
    }

    return NULL;
}

void exercise02() {
    IntVector vector = { 1, 2, 3, 4, 5, 2, 6, 2, 7, 8};

    int *crawler = vector;

    printf("0 [%p]\n", &vector[0]);
    printf("1 [%p]\n", &vector[1]);
    printf("2 [%p]\n", &vector[2]);
    printf("3 [%p]\n", &vector[3]);
    printf("4 [%p]\n", &vector[4]);
    printf("5 [%p]\n", &vector[5]);
    printf("6 [%p]\n", &vector[6]);
    printf("7 [%p]\n", &vector[7]);
    printf("8 [%p]\n", &vector[8]);
    printf("9 [%p]\n", &vector[9]);
    puts("");

    while (1) {
        crawler = find_one(++crawler, &vector[9], 2);

        if (!crawler) break;

        printf("found & = %p\n", crawler);
    }
}

int main() {

    exercise01();
    exercise02();

    return 0;
}