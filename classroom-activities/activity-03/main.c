#include <stdio.h>
#include <math.h>

void exercise01() {
    /* read 5 values and print sum (only 2 variables) */

    printf("Exercise 1 - Provide 5 int values\n");

    int sum = 0, aux;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &aux);
        sum += aux;
    }

    printf("sum = %d\n", sum);
}

void exercise02() {
    /* read 50 values and print odds sum */

    printf("\nExercise 2 - Provide 50 int numbers:\n");

    int sum = 0, num;
    for(int i = 0; i < 50; i++) {
        scanf("%d", &num);
        if(num % 2 != 0) {
            sum += num;
        }
    }
    printf("Odd's sum = %d\n", sum);
}

void exercise03() {
    /* Previous exercise but only odd numbers between [100, 200] */

    printf("\nExercise 3 - Provide 50 int numbers:\n");

    int sum = 0, num;
    for(int i = 0; i < 50; i++) {
        scanf("%d", &num);
        if(num % 2 != 0 && num >= 100 && num <= 200) {
            sum += num;
        }
    }
    printf("Odd's sum between 100 and 200 = %d\n", sum);
}

void exercise04() {
    /* greater and lowest */

    printf("\nExercise 4 - Provide 20 int numbers\n");

    int greater, lowest, num;

    scanf("%d", &num);
    greater = num;
    lowest = num;

    for(int i = 0; i < 19; i++) {
        scanf("%d", &num);

        if(greater < num) {
            greater = num;
        }

        if(lowest > num) {
            lowest = num;
        }
    }
    printf("Greater = %d | Lowest = %d\n", greater, lowest);
}

void exercise05() {
    /* previous exercise but only positive values */

    int greater, lowest, num;

    do {
        printf("\nExercise 5 - Provide 20 positive int numbers\n");

        scanf("%d", &num);

        if(num < 0) {
            printf("Just positive numbers are accepted. Try again. \n");
            continue;
        }

        greater = num;
        lowest = num;

        int i = 0;

        while(i < 19) {
            scanf("%d", &num);

            if(num < 0) {
                printf("Just positive numbers are accepted. Try again. \n");
                continue;
            }

            if(greater < num) {
                greater = num;
            }

            if(lowest > num) {
                lowest = num;
            }

            i++;
        }

        printf("Greater = %d | Lowest = %d\n", greater, lowest);
    } while(num < 0);
}

void exercise06() {
    /* multiplication tables */

    for (int num = 1, i = 1; num <= 9; i++) {
        printf("%d x %d = %d\n", num, i, num * i);

        if (i == 10) {
            i = 0;
            num++;
            printf("\n");
        }
    }
}

void exercise07() {

}

int main() {
//    exercise01();
//    exercise02();
//    exercise03();
//    exercise04();
//    exercise05();
//    exercise06();
    exercise07();
//    exercise08();

    return 0;
}
