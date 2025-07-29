#include <stdio.h>

int A[][4] = {
    {4, 2, 7, 9},
    {6, 3, 1, 5},
    {8, 9, 2, 6},
    {9, 0, 3, 4}
}, dim = 4;

void compare_non_secondary_diagonal_sums() {
    int sumAbove = 0, sumBelow = 0;
    printf("Non secondary diagonal elements: ");
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++) {
            if (i + j < dim - 1) {
                sumAbove += A[i][j];
                printf("%d ", A[i][j]);
            }
            if (i + j > dim - 1) {
                sumBelow += A[i][j];
                printf("%d ", A[i][j]);
            }
        }
    printf("\nSum above: %d\nSum below: %d\n", sumAbove, sumBelow);
    if (sumAbove > sumBelow)
        printf("Sum above secondary diagonal is greater than sum below.");
    else if (sumAbove < sumBelow)
        printf("Sum below secondary diagonal is greater than sum above.");
    else
        printf("Sums above and below secondary diagonal are equal.");
}

void print_primary_diagonal() {
    for (int i = 0; i < dim; i++)
        printf("%d ", A[i][i]);
}

void sum_primary_diagonal() {
    int sum = 0;
    printf("Primary diagonal: ");
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            if (i == j) {
                sum += A[i][j];
                printf("%d ", A[i][j]);
            }
    printf("\nSum primary diagonal: %d\n", sum);
}

void sum_secondary_diagonal() {
    int sum = 0;
    printf("Secondary diagonal: ");
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            if (i + j == dim - 1) {
                sum += A[i][j];
                printf("%d ", A[i][j]);
            }
    printf("\nSum secondary diagonal: %d\n", sum);
}

void print_matrix() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    print_matrix();
    sum_primary_diagonal();
    sum_secondary_diagonal();
    compare_non_secondary_diagonal_sums();
    return 0;
}