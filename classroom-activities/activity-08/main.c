#include <stdio.h>
#include <string.h>

#define ROW 3
#define COL 5

void sum_matrix(int matrix01[][COL], int matrix02[][COL]){

    puts("Matrix sum: ");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%02d ", matrix01[i][j] + matrix02[i][j]);
        }
        printf("\n");
    }
}

void exercise01() {
    int matrix01[ROW][COL] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9,10},
    {11, 12, 13, 14, 15}
    };

    int matrix02[ROW][COL] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9,10},
    {11, 12, 13, 14, 15}
    };

    sum_matrix(matrix01, matrix02);
}

void multiply_by_scalar(int matrix[][ROW], int scalar) {

    puts("Matrix multiplication: ");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < ROW; j++) {
            printf("%02d ", matrix[i][j] * scalar);
        }
        printf("\n");
    }
}

void exercise03() {
    int matrix[ROW][ROW] = {
    {1, 1, 1},
    {2, 2, 2},
    {3, 3, 3}
    };

    multiply_by_scalar(matrix, 3);
}

void find_one(int matrix[][ROW], int target) {

    printf("Searching num... %d\n",target);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < ROW; j++) {
            if (matrix[i][j] == target) {
                printf("Found in pos [%d][%d]\n", i, j);
                return;
            }
        }
    }

    puts("Value not found.");
}

void exercise04() {
    int matrix[ROW][ROW] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    find_one(matrix, 5);
    find_one(matrix, 45);
}

void print_main_diagonal(int matrix[][COL]) {
    puts("Main diagonal: ");
    for (int i = 0; i < COL; i++) {
        printf("%02d ", matrix[i][i]);
    }
    puts("");
}

void print_secondary_diagonal(int matrix[][COL]) {
    puts("Secondary diagonal: ");
    for (int i = 0, j = COL - 1; i < COL; i++, j--) {
        printf("%02d ", matrix[i][j]);
    }
    puts("");
}

void sum_line(int matrix[][COL], int line) {
    int sum = 0;

    printf("Sum line %d:\n", line);
    for (int i = 0; i < COL; i++) {

        sum += matrix[line][i];
        printf("%02d ", matrix[line][i]);
        if (i != COL - 1) {
            printf("+ ");
        }
    }

    printf ("= %d\n", sum);
}

void sum_column(int matrix[][COL], int column) {
    int sum = 0;

    printf("Sum column %d:\n", column);
    for (int i = 0; i < COL; i++) {

        sum += matrix[i][column];
        printf("%02d ", matrix[i][column]);
        if (i != COL - 1) {
            printf("+ ");
        }
    }

    printf ("= %d\n", sum);
}

void exercise05() {
    int matrix[COL][COL] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9,10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25},
    };

    print_main_diagonal(matrix);
    print_secondary_diagonal(matrix);
    sum_line(matrix, 4);
    sum_column(matrix, 2);
}



int main() {

//    exercise01();
//    exercise03();
//    exercise04();
//    exercise05();

    return 0;
}