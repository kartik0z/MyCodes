#include <stdio.h>

int main() {
    int i = 1;
    int count = 0; 

    while (i <= 20) {
        printf("%d\n", i); 
        count++; 
        i += 2; 
    }

    printf("Total number of odd numbers from 1 to 20 is: %d\n", count); 

    return 0;
}