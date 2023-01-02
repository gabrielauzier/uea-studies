#include <stdio.h>
#include <math.h>

void exercise01() {
    /* calculate sqrt */

    int y;
    printf("Digit a number:");
    scanf("%d", &y);

    float next = y, previous = y / 2.0, dif;

    do {
        next = previous - (previous * previous - y) / (2 * previous);

        dif = next - previous;
        previous = next;

    } while (fabs(dif) > 1e-9);

    printf("[manual] sqrt = %.10f\n", next);
    printf("[math.h] sqrt = %.10f\n", sqrt(y));
}

void exercise02() {
    /* greater and lowest */

    float greater, lowest, num;

    printf("\nDigit 15 real numbers\n");
    scanf("%f", &num);

    greater = num;
    lowest = num;

    for(int i = 0; i < 14; i++) {
        scanf("%f", &num);

        if(greater < num) {
            greater = num;
        }

        if(lowest > num) {
            lowest = num;
        }
    }
    printf("Greater = %.2f | Lowest = %.2f\n", greater, lowest);
}

void exercise03() {
    int num, oddSum = 0, evenSum = 0;

    while (scanf("%d", &num) && num <= 1000) {
        if(num % 2 == 0) evenSum += num;
        else oddSum += num;
    };

    printf("Odd Sum = %d\nEven Sum = %d", oddSum, evenSum);
}

void exercise04() {
    /* prime number */

    int num, isPrime = 1;

    printf("Digit a number:\n");
    scanf("%d", &num);

    if (num == 1 || num % 2 == 0) isPrime = 0;
    if (num == 2) isPrime = 1;

    for (int i = 3; i < num / 2; i++) {
        if (num % i == 0){
            isPrime = 0;
            break;
        }
    }

    isPrime ? printf("%d is prime\n", num) : printf("%d is not prime\n", num);
}

void exercise05() {
    /* sequence sum */

    int a, b;
    float sum = 0;

    for (a = 1, b = 1; b <= 50; a += 2, b++ ) {
        sum += a / b;
    }

    printf("Sum = %f", sum);
}

void exercise06() {
    /* perfect number */

    int num, sum = 0;

    printf("Digit a number:\n");
    scanf("%d", &num);

    for (int i = 1; i <= num / 2; i++) {
        if(num % i == 0) sum += i;
    }

    sum == num ? printf("%d is perfect\n", num) : printf("%d is not perfect\n", num);
}

void exercise07() {
    /* radioactive material */

    const int DECAY_RATE = 50;
    int time = 0;
    float mass;
    printf("Digit the initial mass:\n");
    scanf("%f", &mass);

    printf("Initial mass = %.2f g\n", mass);

    while (mass >= 0.5) {
        mass /= 2;
        time += DECAY_RATE;
    }

    printf("Final mass = %.2f g\n", mass);
    int hour, min, sec;
    hour = time / 3600;
    min = (time % 3600) / 60;
    sec = (time % 3600) % 60;

    printf("Total time = %02d:%02d:%02d\n", hour, min, sec);
}

void exercise08() {
    /* rectangle triangle */

    int n;
    printf("Digit (n) value:\n");
    scanf("%d", &n);

    int a = 1, b = 1, c;

    for (int i = 1; i <= n; i++, a = 1, b = 1) {
        c = i * i;

        while (a < n) {
            while (b < n) {
                int hip = a * a + b * b;
                if (c == hip) {
                    printf("%d ", i);
                    a = n;
                    break;
                }
                b++;
            }
            a++;
            b = a;
        }
    }
}

void exercise09() {
    /* max values */

    int n, m;
    printf("Digit (n) and (m) values:\n");
    scanf("%d %d", &n, &m);

    int x = 0, y = 0, max = 0;
    int maxX = x, maxY = y;

    while (x <= m) {
        while (y <= n) {

            int aux = x * y - x * x + y;
            if (max < aux) {
                max = aux;
                maxX = x;
                maxY = y;
            }

            y++;
        }

        x++;
        y = 1;
    }

    printf("Max = %d\nx = %d\ny = %d\n", max, maxX, maxY);
}

void exercise10() {
    /* n³ problem */
    int num;

    printf("Digit a number (n):");
    scanf("%d", &num);

    int start = 1;

    for (int i = 1; i <= num; i++) {
        start += 2 * i;
    }

    printf("n^3 is equal sum of = ");
    start -= 2 * num;
    for (int i = 1; i <= num; i++, start += 2) {
        printf("%d ", start);
    }
}

int main() {
//    exercise01();
//    exercise02();
//    exercise03();
//    exercise04();
//    exercise05();
//    exercise06();
//    exercise07();
//    exercise08();
    exercise09();
//    exercise10();

    return 0;
}