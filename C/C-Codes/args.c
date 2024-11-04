#include <stdio.h>
#include <stdlib.h> // For atoi function to convert string to integer

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please provide exactly two integers as command-line arguments.\n");
        return 1;
    }

    // Convert command-line arguments from strings to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Calculate the sum
    int sum = num1 + num2;

    // Print the sum
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}
