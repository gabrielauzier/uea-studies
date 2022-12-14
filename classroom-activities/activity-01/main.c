#include <stdio.h>


void exercise01() {
    float base, height, area;

    printf("Exercise 01 - Write the base and height:");
    scanf("%f %f", &base, &height);

    area = base * height / 2;
    printf("Area = %.2f\n", area);
}

void exercise02() {
    float wage;

    printf("Exercise 02 - How much you earn?");
    scanf("%f", &wage);

    float newWage = wage * 1.10;
    printf("If your wage increases 10%%, you'll earn $%.2f\n", newWage);
}

void exercise03() {
    float totalBill, waiterPercent;

    printf("Exercise 03 - Provide us the bill value and the waiter percentage you want to give. (Obs: provide the percentage in decimal format) \n");
    scanf("%f %f", &totalBill, &waiterPercent);

    float totalForWaiter = totalBill *  (waiterPercent / 100 );
    printf("The waiter must receive $%.2f", totalForWaiter);
}

int main() {

    exercise01();
    exercise02();
    exercise03();

    return 0;
}
