#include <stdio.h>

int main() {
    int a[2][2], b[2][2], result[2][2];

    // Input elements of the first matrix
    printf("Enter elements of the 2x2 matrix A:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    // Input elements of the second matrix
    printf("Enter elements of the 2x2 matrix B:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);

    // Multiply the matrices
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += a[i][k] * b[k][j];
        }

    // Output the result matrix
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

return 0;
}