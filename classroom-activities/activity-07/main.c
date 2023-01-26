#include <stdio.h>
#define GET_INT_LEN(x) (sizeof(x) / sizeof((x)[0]))
#define NUMS_LEN 5

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

int main() {
    exercise03();

    return 0;
}