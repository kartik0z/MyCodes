#include <stdio.h>

int main() {
    int i, j, k;
    int n = 4; //Number of rows

    for (i = 1; i <= n; i++) 
    {
        for (j = i; j < n; j++) //printing leading spaces
        {
            printf(" ");
        }
        
        for (k = 1; k <= (2 * i - 1); k++) //Print stars with spaces in between
        {
            if (k % 2 == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n"); //Move to the next line
    }

    return 0;
}