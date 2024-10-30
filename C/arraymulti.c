#include <stdio.h>

int main() {
    int rows1 = 2, cols1 = 2, rows2 = 2, cols2 = 2;
    int matrix1[2][2], matrix2[2][2], product[2][2];

    // Taking input for the first matrix
    printf("Enter elements for the first 2x2 matrix:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Taking input for the second matrix
    printf("Enter elements for the second 2x2 matrix:\n");
    for(int i = 0; i < rows2; i++) {
        for(int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Check if matrix multiplication is possible (i.e., cols1 == rows2)
    if (cols1 == rows2) {
        // Initialize product matrix to 0
        for(int i = 0; i < rows1; i++) {
            for(int j = 0; j < cols2; j++) {
                product[i][j] = 0;
            }
        }

        // Multiplying the two matrices
        for(int i = 0; i < rows1; i++) {
            for(int j = 0; j < cols2; j++) {
                for(int k = 0; k < cols1; k++) {
                    product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        // Displaying the product matrix
        printf("Product of the matrices:\n");
        for(int i = 0; i < rows1; i++) {
            for(int j = 0; j < cols2; j++) {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    } else {
        // Else part if multiplication isn't possible
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
    }

    return 0;
}