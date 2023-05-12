#include <stdio.h>
#include <math.h>

void exercise01() {
    /* two number sum */

    float num1, num2;

    printf("Exercise 01 - Give me two numbers:\n");
    scanf("%f %f", &num1, &num2);
    float sum = num1 + num2;

    printf("Sum = %.2f\n", sum);
}

void exercise02() {
    /* grades */

    printf("Exercise 02:\n");

    float gradesTotal = 0;
    int gradesCounter = 0;
    float grade;

    while(gradesCounter < 4) {

        printf("Give me grade %d:\n", gradesCounter + 1);
        scanf("%f", &grade);

        if (grade < 0) {
            printf("Grade value invalid. \n");
            continue;
        }

        gradesTotal += grade;
        gradesCounter++;
    }

    float average = gradesTotal / 4.0;
    printf("Average = %.2f\n", average);
}

void exercise03() {
    /* meters to centimeters converter */

    float value;

    printf("Exercise 03 - Provide a value in meters:\n");
    scanf("%f", &value);

    value *= 100;
    printf("Value in centimeters: %.2f\n", value);
}

void exercise04() {
    /* circle area */

    float ray;
    printf("Exercise 04 - Give me the ray of circle:\n");
    scanf("%f", &ray);

    const float area = M_PI * ray * ray;
    printf("Circle area = %.2f\n", area);
}

void exercise05() {
    /* square area */

    float squareSide;
    printf("Exercise 05 - Give me the side of square:\n");
    scanf("%f", &squareSide);

    printf("Square area = %.2f\nSquare doubled area = %.2f\n", squareSide * squareSide, squareSide * squareSide * 2);
}

void exercise06() {
    /* money per hour */

    float wagePerHour;
    int workedHours;

    printf("Exercise 05\n");

    printf("How much you earn per hour?\n");
    scanf("%f", &wagePerHour);
    printf("How many hours you worked this month?\n");
    scanf("%d", &workedHours);

    float totalCashEarned = wagePerHour * workedHours;

    printf("Total cash earned = $%.2f\n", totalCashEarned);
}

void exercise07() {
    /* temperature converter Fahrenheit to Celsius */

    float tempInFahrenheit;
    printf("Exercise 07 - Give me some temperature in Fahrenheit:\n");
    scanf("%f", &tempInFahrenheit);

    float tempInCelsius = 5 * ((tempInFahrenheit - 32) / 9);
    printf("Temperature in Celsius = %.1f\n", tempInCelsius);
}

void exercise08() {
    /* temperature converter Celsius to Fahrenheit */

    float tempInCelsius;
    printf("Exercise 08 - Give me some temperature in Celsius:\n");
    scanf("%f", &tempInCelsius);

    float tempInFahrenheit = (tempInCelsius) * 9 / 5 + 32;
    printf("Temperature in Fahrenheit = %.1f\n", tempInFahrenheit);
}

void exercise09() {
    /* calculus */

    int int01, int02;
    float realNum;

    printf("Exercise 09 - Give me two int numbers and one real:\n");
    scanf("%d %d %f", &int01, &int02, &realNum);

    const float result01 = int01 * 2 * (int02 / 2), result02 = int01 * 3 + realNum, result03 = realNum * realNum * realNum;
    printf("Result 01 = %.2f\nResult 02 = %.2f\nResult 03 = %.2f\n", result01, result02, result03);
}

void exercise10() {
    /* ideal weight calculator */

    printf("Exercise 10\n");

    float idealWeight, height;
    printf("What is your height in meters?\n");
    scanf("%f", &height);

    idealWeight = 72.7 * height - 58;
    printf("Your ideal weight is: %.2f kg\n", idealWeight);
}

void exercise11() {
    /* accountability calculator */

    printf("Exercise 11\n");

    float moneyPerHour, workedHours;
    printf("How much you earn per hour?\n");
    scanf("%f", &moneyPerHour);
    printf("How many hours you worked this month?\n");
    scanf("%f", &workedHours);

    float grossSalary = moneyPerHour * workedHours;
    float totalDiscountIR = 0.11 * grossSalary;
    float totalDiscountINSS = 0.08 * grossSalary;
    float totalDiscountSyndicate = 0.05 * grossSalary;

    float netSalary = grossSalary - totalDiscountIR - totalDiscountINSS - totalDiscountSyndicate;
    printf("Gross salary = $%.2f\nINSS = $%.2f\nSyndicate = $%.2f\nNet salary = $%.2f\n", grossSalary, totalDiscountINSS, totalDiscountSyndicate, netSalary);
}

int main() {

    exercise01();
    exercise02();
    exercise03();
    exercise04();
    exercise05();
    exercise06();
    exercise07();
    exercise08();
    exercise09();
    exercise10();
    exercise11();

    return 0;
}
