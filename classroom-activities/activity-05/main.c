#include <stdio.h>
#include <math.h>

/* Exercise 01 - functions */
int scanIntInterval();
float getPercent(int x, int y);
float absDif(float x, float y);

/* Exercise 02 - functions */
void scanWeightAndWeeksOfGestation(float *weight, float *weeksOfGestation);
void verifyWeightAndGestation(float weight, int weeksOfGestation);

/* Exercise 03 - functions */
int scanAndVerifyNum();
int isNumPerfect(int num);

/* Exercise 04 - functions */
int factorial(int num);

/* Exercise 05 - functions */
int fibonacci(int num);

/* Solutions */

void exercise01() {
    int x, y, lowest, greater;

    printf("[01] Digit (x) value\n");
    x = scanIntInterval();
    printf("[01] Digit (y) value\n");
    y = scanIntInterval();

    if (x > y) {
        lowest = y;
        greater = x;
    } else {
        lowest = x;
        greater = y;
    }

    printf("Greater = %d\nLowest = %d\n", greater, lowest);

    float percent = getPercent(lowest, greater);
    printf("Percent = %.2f %%\n", percent);

    float dif = absDif(x, y);
    printf("Absolute difference = %.0f\n", dif);
}

int scanIntInterval() {
    int num;
    scanf("%d", &num);

    while (num > 1000 || num < 0) {
        printf("Out of interval. \n");
        scanf("%d", &num);
    }

    return num;
}

float getPercent(int x, int y) {
    return x / (y * 1.0) * 100.0;
}

float absDif(float x, float y) {
    return fabs(x - y);
}

void exercise02() {
    float weight = 0, weeksOfGestation = 0;

    printf("[02] Digit the weight and weeks of gestation\n");
    scanWeightAndWeeksOfGestation(&weight, &weeksOfGestation);
    verifyWeightAndGestation(weight, weeksOfGestation);
}

void scanWeightAndWeeksOfGestation(float *weight, float *weeksOfGestation) {
    scanf("%f %f", weight, weeksOfGestation);
}

void verifyWeightAndGestation(float weight, int weeksOfGestation) {
    if (weight < 100.0 || weeksOfGestation < 28) {
        printf("Childbirth should not be done. Consult doctor. \n");
        return;
    }

    int monthQtd = (int) weeksOfGestation / 4;

    if (weight > 2500.0 && monthQtd > 7) printf("Normal childbirth. \n");
    else if (weight > 2500.0 && monthQtd <= 7) printf("Cesarean childbirth. \n");
    else if (weight <= 2000.0 && weight >= 1500.0 && monthQtd >= 9) printf("Normal childbirth. \n");
    else printf("Cesarean childbirth. \n");
}

void exercise03() {
    int num;

    printf("[03] Digit num\n");
    num = scanAndVerifyNum();

    isNumPerfect(num) ? printf("%d is perfect. \n", num) : printf("%d is not perfect. \n", num);
}

int scanAndVerifyNum() {
    int num;
    scanf("%d", &num);

    while (num % 2 != 0 || num < 0) {
        if (num % 2 != 0) printf("Invalid: odd num. Try again. \n");
        if (num < 0) printf("Invalid: negative num. Try again. \n");

        scanf("%d", &num);
    }

    return num;
}

int isNumPerfect(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if(num % i == 0) sum += i;
    }

    return sum == num ? 1 : 0;
}

void exercise04() {
    int num;
    printf("[04] Factorial\n");

    do {
        printf("Digit a number. (negative number to exit)\n");
        scanf("%d", &num);
        printf("Factorial = %d\n", factorial(num));
    } while (num >= 0);
}

int factorial(int num) {
    if (num == 0 || num == 1) return 1;

    return num * factorial(num - 1);
}

void exercise05() {
    int num;

    printf("[05] Fibonacci\n");

    do {
        printf("Digit a number. (negative number to exit)\n");
        scanf("%d", &num);
        printf("Fibonacci = %d\n", fibonacci(num));
    } while (num >= 0);
}

int fibonacci(int num) {
    int previous = 1, actual = 1;
    int next = previous + actual;

    if (num == 0) return 0;
    if (num == 1 || num == 2) return 1;

    for (int i = 3; i <= num; i++) {
        next = previous + actual;

        previous = actual;
        actual = next;
    }

    return next;
}

int main() {

    exercise01();
    exercise02();
    exercise03();
    exercise04();
    exercise05();

    return 0;
}