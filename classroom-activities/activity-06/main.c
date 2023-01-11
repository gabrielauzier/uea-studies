#include <stdio.h>
#include <math.h>

/* Exercise 01 */
int getDigitRepetition(int n, int d) {
    int counter = 0;

    while (n) {
        int res = n % 10;

        if (res == d) counter++;

        n /= 10;
    }

    return counter;
}

void exercise01() {
    int n, d;

    printf("Ex 01:\n");
    scanf("%d %d", &n, &d);

    printf("Digit %d appears %d times", d, getDigitRepetition(n, d));
}

/* Exercise 02 */
int verifyPermutation(int a, int b) {
    int isPermutation = 1;

    for (int i = 1; i <= 9; i++) {
        if (getDigitRepetition(a, i) != getDigitRepetition(b, i)) isPermutation = 0;
    }

    return isPermutation;
}

 void exercise02() {
    int a, b;
    printf("Ex 2:\n");
    scanf("%d %d", &a, &b);

    printf("result = %d", verifyPermutation(a, b));
}

/* Exercise 03 */
int numSize(int temp) {
    int size = 0;
    while (temp) {
        size++;
        temp /= 10;
    }
    return size;
}

/* Verify if x contains y */
int numContains(int x, int y) {
    int y_size = numSize(y), tens = 1;

    tens = pow(10, y_size);

    while (x) {
        if ( x % tens == y) return 1;
        x /= 10;
    }

    return 0;
}

/* Verify if x contains y in the last digits */
int numContainsInFinal(int x, int y) {
    while (y != 0 && x % 10 == y % 10) {
        x /= 10;
        y /= 10;
    }

    return y == 0 ? 1 : 0;
}

void exercise03() {
    int x, y, isWithin = 0;
    printf("Ex 3;\n");
    scanf("%d %d", &x, &y);

    int greater, lowest;
    if (x > y) {
        greater = x;
        lowest = y;
    } else {
        greater = y;
        lowest = x;
    }

    while (greater >= lowest) {
        if (numContainsInFinal(greater, lowest) == 1) isWithin = 1;
        greater /= 10;
    }

    printf("result = %d\n", isWithin);
}

/* Exercise 04 */
void exercise04() {

}

/* Exercise 05 */
int binToDecimal(long long n) {
    int dec = 0, i = 0, rem;

    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

void exercise05() {
    long long bin;
    scanf("%lld", &bin);
    printf("Decimal = %d\n", binToDecimal(bin));
}

/* Exercise 06 */
long long decimalToBin(int n) {
    long long bin = 0;
    int rem, i = 1;

    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

void exercise06() {
    int dec;
    scanf("%d", &dec);
    printf("Binary = %lld\n", decimalToBin(dec));
}

int main() {

    exercise01();
    exercise02();
    exercise03();
    exercise04();
    exercise05();
    exercise06();

    return 0;
}