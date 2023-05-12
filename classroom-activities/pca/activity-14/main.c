/* activity 13 part 2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define LINE() (printf("\n"))
#define GET_ARRAY_LEN(x)  (sizeof(x) / sizeof((x)[0]))

typedef char string[255];

void print_int(string key, int value) {
    printf("%s = %d", key, value);
    LINE();
}

void print_float(string key, float value) {
    printf("%s = %.2f", key, value);
    LINE();
}

void exercise03() {
    int num = 1;
    float numReal = 1.0;
    char c = 'k';

    int *p_num = &num;
    float *p_real = &numReal;
    char *p_char = &c;

    puts("before");
    print_int("num", num);
    print_float("real", numReal);
    print_int("char", c);
    LINE();

    *p_num = 2;
    *p_real = 31.2;
    *p_char = 'z';

    puts("after");
    print_int("num", num);
    print_float("real", numReal);
    print_int("char", c);
}

void scan_and_print_doubled_array(int *array, int *End) {
    while (array <= End) {
        printf("%d x 2 = %d", *array, (*array) * 2);
        LINE();
        array++;
    }
}

void exercise04() {
    int array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    scan_and_print_doubled_array(array, &array[GET_ARRAY_LEN(array) - 1]);
}

void scan(int *array, int len) {
    for (int i = 0; i < len; i++)
        scanf_s("%d", &array[i]);
}

void trade(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int sort(int *a, int *b, int *c) {
    if (*a == *b || *b == *c || *a == *c) return 1;

    if (*a < *b && *a < *c) {
        if (*c < *b) trade(b, c);
    }

    if (*b < *a && *b < *c) {
        if (*c < *a) trade(a, c);
        trade(a, b);
    }

    if (*c < *a && *c < *b) {
        if (*b < *a) trade(a, b);
        trade(a, c);
    }

    if (*b > *c) trade (b, c);

    return 0;
}

void print_array(int *array, int len) {
    printf("Array = [");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);

        if (i < len - 1)
            printf(", ");
        else
            printf("]\n");
    }
}

void exercise05() {
    int array[3];

    scan(array, 3);

    print_array(array, 3);
    sort(&array[0], &array[1], &array[2]);

    print_array(array, 3);
}

#define tam 10

typedef int IntArray[tam];

IntArray * sum_arrays(int *array1, int *array2) {
    IntArray *result = malloc(sizeof (IntArray));

    int count = 0;
    while (count < tam) {
        *result[count] = *array1 + *array2;

        array1++;
        array2++;
        count++;
    }

    return result;
}

void print_int_array(IntArray src) {
    printf("IntArray = [");
    for (int i = 0; i < tam; i++) {
        printf("%d", src[i]);

        if (i < tam - 1)
            printf(", ");
        else
            printf("]\n");
    }
}

int run_exercise_06() {
    IntArray a = {1, 2, 3};
    IntArray b = {4, 5, 6};

    if (GET_ARRAY_LEN(a) != GET_ARRAY_LEN(b)) return 0;

    IntArray *result = sum_arrays(a, b);

    print_int_array(*result);

    return 1;
}

void exercise06() {
    run_exercise_06();
}

void cpy_min_max(IntArray src, int *a, int *b) {
    *a = src[0];
    *b = src[0];

    for (int i = 0; i < tam; i++) {
        if (src[i] < *a) *a = src[i];
        if (src[i] > *b) *b = src[i];
    }
}

void exercise07() {
    IntArray a = { 1314, 22341, 213, 2, 132, 423, 1, 243, 3841, 218 };
    int min, max;

    cpy_min_max(a, &min, &max);
    print_int("min", min);
    print_int("max", max);
}

void trade_float(float *a, float *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void exercise08() {
    float a = 2.0, b = 3.0;

    trade_float(&a, &b);
    print_float("a", a);
    print_float("b", b);
}

char * count_char(char *src, char target) {
    int count = 0;
    const size_t len = strlen(src);
    int *list = malloc(sizeof (int) * len);

    print_int("len", strlen(src));

    for (int i = 0; i < strlen(src); i++) {
        if (src[i] == target) {
            list[count] = i;
            count++;
        }
    }

    int i;
    char *result = malloc(sizeof (char) * (count + 1));

    for (i = 0; i < count; i++) {
        print_int("i", list[i]);
        result[i] = list[i]+'0';
    }
    result[i] = '\0';

    return result;
}

void show_string(string result) {
    printf("String[%d] = [", strlen(result));
    for (int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]);

        if (i < strlen(result) - 1)
            printf(", ");
        else
            printf("]");
    }
}

void exercise09() {
    char * result = count_char("aaaababamabz", 'z');

    show_string(result);
}

int main() {

    exercise03();
    exercise04();
    exercise05();
    exercise06();
    exercise07();
    exercise08();
    exercise09();

    return 0;
}