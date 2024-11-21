#include <stdio.h>

// Function to calculate factorial using recursion
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci term using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num, terms, i;

    // Factorial Calculation
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is: %lld\n", num, factorial(num));
    }

    // Fibonacci Series
    printf("\nEnter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Number of terms must be positive.\n");
    } else {
        printf("Fibonacci series up to %d terms:\n", terms);
        for (i = 0; i < terms; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}