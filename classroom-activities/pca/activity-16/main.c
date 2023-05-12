#include <stdio.h>
#include <stdlib.h>

#define line() (printf("\n"))
#define title(s) (printf("\n%s:\n", s))

int * create_vector(int t) {
    int * vector = (int *) malloc(sizeof (int) * t);
    return vector;
}

void scan_vector(int *vector, int t) {
    for (int i = 0; i < t; i++, vector++) {
        scanf("%d", vector);
    }
}

int get_max(int *vector, int t) {
    int greater = *vector;
    for (int i = 0; i < t; i++, vector++) {
        if (greater < *vector) {
            greater = *vector;
        }
    }

    return greater;
}

int get_min(int *vector, int t) {
    int lowest = *vector;
    for (int i = 0; i < t; i++, vector++) {
        if (lowest > *vector) {
            lowest = *vector;
        }
    }

    return lowest;
}

int * get_extremes(int *vector, int t) {
    int max = get_max(vector, t);
    int min = get_min(vector, t);

    int *new = malloc(sizeof (int) * 2);

    *new = max;
    *(new + 1) = min;

    return new;
}

void exercise01() {
    int t = 5;

    int *vector = create_vector(t);
    scan_vector(vector, t);

    int *values = get_extremes(vector, t);

    title("Max and Min");
    printf("\nmax = %d", *values);
    printf("\nmin = %d", *(values + 1));
}

int * create_matrix(int m, int n) {
    int * matrix = (int *) malloc(sizeof (int) * m * n);

    return matrix;
}

double ** create_matrix_2(int rows, int cols) {
    double ** matrix = (double **) malloc(rows * sizeof (double *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (double *) malloc(cols * sizeof (double));

    return matrix;
}

//void init_matrix(double ** matrix, int rows, int cols) {
//
//}

void scan_matrix(double ** matrix, int rows, int cols) {
    title("Scan");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("m(%d, %d):", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix_formatted(double ** matrix, int rows, int cols) {
    title("Matrix formatted");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("(%5.1lf) ", *(*(matrix + i) + j));
        }
        line();
    }
}

void print_matrix_2(double ** matrix, int rows, int cols) {
    title("Matrix 2.0");
    for (int i = 0; i < rows * cols; i++) {
        printf("%-5.1lf | %u", **matrix, *matrix);
        line();

        if ((i + 1) % cols == 0) {
            (*&matrix)++;
            continue;
        }

        (*matrix)++;
    }
}

double ** sum_matrices(double **matrix1, double **matrix2, int rows, int cols) {
    double ** result = create_matrix_2(rows, cols);

    title("Sum matrices");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

void exercise02() {
    int m = 3, n = 2;

    /* part 1 */
    double ** matrix = create_matrix_2(m, n);

    scan_matrix(matrix, m, n);
    print_matrix_formatted(matrix, m, n);
//    print_matrix_2(matrix, m, n);

    /* part 2 */
    double ** matrix_2 = create_matrix_2(m, n);

    scan_matrix(matrix_2, m, n);
    print_matrix_formatted(matrix_2, m, n);
//    print_matrix_2(matrix_2, m, n);

    double ** result = sum_matrices(matrix, matrix_2, m, n);

    print_matrix_formatted(result, m, n);

    for (int i = 0; i < 3; i++)
}

int main() {
//    exercise01();
    exercise02();

    return 0;
}