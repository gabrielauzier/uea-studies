#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printString(char *string) {

    printf("\nYour string: ");
    for (int i = 0; i < strlen(string) ; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void printReverse(char *string) {
    printf("\nReverse: ");
    for (int i = strlen(string) - 1; i >= 0 ; i--) {
        printf("%c", string[i]);
    }
    printf("\n");
}

int isVowel(char c) {
    switch (tolower(c)) {
        case 'a': return 1;
        case 'e': return 1;
        case 'i': return 1;
        case 'o': return 1;
        case 'u': return 1;
        default: return 0;
    }
}

void printWithoutVowels(char *string) {
    printf("\nWithout vowels: ");
    for (int i = 0; i < strlen(string); i++) {
        if (isVowel(string[i]) == 0) {
            printf("%c", string[i]);
        }
    }
    printf("\n");
}

void stringToUpper(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }
}

int countChar(char *string, char c) {
    int counter = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == c) {
            counter++;
        }
    }

    return counter;
}

void deleteChar(char *string, char c) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == c) {
            int j;
            for (j = i; j < strlen(string) - 1; j++) {
                string[j] = string[j + 1];
            }
            string[j] = '\0';
            i = i - 1;
        }
    }
}

void exercise01() {
    char string[100] = "aabbccddaaee";

//    scanf("%s", string);

    printReverse(string);
    printWithoutVowels(string);

    stringToUpper(string);
    printString(string);

    printf("\nChar frequency: %d\n", countChar(string, 'A'));

    deleteChar(string, 'A');
    printString(string);
}

void exercise02() {
    int cars = 5;

    char matrix[][20] = {"Fusca", "Gol", "Vetra", "Onix", "Renaut"};
    int kmPerLiters[] = {20, 10, 12, 14, 8};

    int mostEconomic, betterConsumption = 0;
    for (int i = 0; i < cars; i++) {
        if (kmPerLiters[i] > betterConsumption) {
            betterConsumption = kmPerLiters[i];
            mostEconomic = i;
        }
    }

    printf("Most economic car is %s\n", matrix[mostEconomic]);
}

void exercise03() {
    char date[] = "01/1/212";
    int barIndexes[] = {2, 5};

    for (int i = 0; i < strlen(date); i++) {
        if (!isdigit(date[i]) && date[i] != '/') {
            printf("Exception: invalid format. [%c] is not a digit.", date[i]);
            return;
        }

        if (i == barIndexes[0] || i == barIndexes[1]) {
            if (date[i] != '/') {
                printf("Exception: bar character wrong placement. Must be in index: %d", i);
                return;
            }
        }
    }

    char *array[3];
    int i = 0;

    array[i] = strtok(date, "/");

    while(array[i] != NULL) {
        array[++i] = strtok(NULL, "/");
    }

    int day = (int) strtol(array[0], (char **) NULL, 10);
    int month = (int) strtol(array[1], (char **) NULL, 10);
    int year = (int) strtol(array[2], (char **) NULL, 10);

    printf("%d %d %d", day, month, year);
}

void exercise04() {

}

void exercise05() {}

void exercise06() {}

int main() {

//    exercise01();
//    exercise02();
    exercise03();
    exercise04();
    exercise05();
    exercise06();
    return 0;
}