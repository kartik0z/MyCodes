#include <stdio.h>

int main() {
    int matrix1[2][2], matrix2[2][2], sum[2][2];

    // Taking input for the first matrix
    printf("Enter elements for the first 2x2 matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Taking input for the second matrix
    printf("Enter elements for the second 2x2 matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Adding two matrices
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            sum[i][j] = matrix1[i][j] * matrix2[i][j];
            printf("Sum of element [%d][%d]: %d\n", i, j, sum[i][j]);
        }
    }

    return 0;
}