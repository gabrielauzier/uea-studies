#include <stdio.h>
#define GET_INT_LEN(x) (sizeof(x) / sizeof((x)[0]))
#define NUMS_LEN 7

void exercise01() {
    int nums[NUMS_LEN];

    for (int i = 0; i < NUMS_LEN; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = NUMS_LEN - 1; i >= 0; i--) {
        printf("%d ", nums[i]);
    }
}

void exercise02() {
    int nums[NUMS_LEN];

    for (int i = 0; i < NUMS_LEN; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = NUMS_LEN - 1; i >= 0; i--) {
        printf("%d ", nums[i]);
    }
}

void exercise03() {
    int nums[NUMS_LEN];

    for (int i = 0; i < NUMS_LEN; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = NUMS_LEN - 1; i >= 0; i--) {
        printf("%d ", nums[i]);
    }

    printf("Len of is %lld", GET_INT_LEN(nums));
}

//
//int reverse_array (int nums[]) {
//
//}

void printArray(int *array, int size) {
    int i = 0;
    printf("Array = ");

    while (i < size) {
        printf("%d ", *array);
        array++; i++;
    }
    printf("\n");
}

void exercise06() {
    int array[NUMS_LEN] = {7,90,1,3,0, 100 ,2};

    printArray(array, NUMS_LEN);
    int i, j;
    for (i = 0; i < NUMS_LEN; i++) {
        int lowest = array[i], lowestIndex = i;

        for (j = i; j < NUMS_LEN; j++) {
            if (array[j] < lowest) {
                lowest = array[j];
                lowestIndex = j;
            }
        }

        int aux = array[i];
        array[i] = array[lowestIndex];
        array[lowestIndex] = aux;

        printArray(array, NUMS_LEN);
    }
}

int main() {
    exercise06();

    return 0;
}