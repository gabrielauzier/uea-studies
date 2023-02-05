#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

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

void scanString(char *string) {
    fgets(string, 255, stdin);
}

int compareStrings(char *string1, char *string2) {
    const int len1 = strlen(string1), len2 = strlen(string2);
    int len;
    if (len1 >= len2) {
        len = len2;
    } else {
        len = len1;
    }

    int isEqual = 1;
    for (int i = 0; i < len; i++) {
        if (string1[i] != string2[i])
            isEqual = 0;
    }

    return isEqual;
}

void concatStrings(char *string1, char *string2) {
    const int len1 = strlen(string1), len2 = strlen(string2);
    int len = len1 + len2;

    char newString[len + 1];

    int i = 0;
    for (int k = 0; k < len1; k++, i++) {
        newString[k] = string1[k];
    }

    for (int k = 0; k < len2; k++, i++) {
        newString[k] = string2[i];
    }

    printf("\nConcat = %s", newString);
}

void replaceFirst(char *string, char c1, char c2) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == c1) {
            string[i] = c2;
            return;
        }
    }
}

void exercise04() {

    printf("\nMenu\n");
    printf("\n(a) - scan string1 1");
    printf("\n(b) - print string1 1");
    printf("\n(c) - compare strings ");
    printf("\n(d) - concat strings ");
    printf("\n(e) - print string1 1 in reverse ");
    printf("\n(f) - count char in string1 1 ");
    printf("\n(g) - replace char ");
    printf("\n(h) - verify substring ");
    printf("\n(i) - get substring ");
    printf("\n(x) - exit");
    printf("\n");

    char string1[20], string2[20];
    char c, c1, c2;

    do  {
        switch(getch()) {
            case 'a':
                printf("\nString 1 = ");
                scanString(string1);
                break;
            case 'b':
                printf("\nString 1 = ");
                printString(string1);
                break;
            case 'c':
                printf("\nString 2 = ");
                scanString(string2);
                compareStrings(string1, string2) == 1 ? printf("\nStrings are equal.") : printf("\nStrings are different.");
                break;
            case 'd':
                printf("\nString 2 = ");
                scanString(string2);
                concatStrings(string1, string2);
                break;
            case 'e':
                printReverse(string1);
                break;
            case 'f':
                printf("\nChar = ");
                scanf("%c", &c);
                printf("\n%c appears %d times", c, countChar(string1, c));
                break;
            case 'g':
                printf("\nChar1 = ");
                scanf("%c", &c1);
                printf("\nChar2 = ");
                scanf("%c", &c2);
                replaceFirst(string1, c1, c2);
                break;
            case 'h':
            case 'x': return;
            default: printf("\nInvalid. ");
        }
    } while (1);

    printf("Exit.");
}

void shift(char *string, int shift) {
    for (int i = 0; i < strlen(string); i++) {

        if (string[i] + shift > 'Z') {
            string[i] = string[i] + 'A' - 'Z' - 1;
        }

        if (string[i] != ' ') {
            string[i] = string[i] + shift;
        }
    }
}

void exercise05() {
    char string[255] = "a ligeira raposa marrom saltou sobre o cachorro cansado";
    stringToUpper(string);
    shift(string, 3);

    printString(string);
}

int isPalindrome(char *string) {
    int result = 1;
    for (int i = 0, e = strlen(string) - 1; i < strlen(string) / 2; i++, e--) {
        if (string[i] != string[e]) result = 0;
    }
    return result;
}

void removeSpaces(char *string) {
    deleteChar(string, ' ');
}

void exercise06() {
    char string[255] = "socorram me subi no onibus em marrocos";
    removeSpaces(string);
    stringToUpper(string);
    isPalindrome(string) == 1 ? printf("\nString is palindrome") : printf("\nString is not palindrome");
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