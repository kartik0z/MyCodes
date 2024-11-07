#include <stdio.h>
#include <stdbool.h>

// Function to get a valid probability between 0 and 1
double getValidProbability(const char *prompt) {
    double probability;
    bool valid = false;

    while (!valid) {
        printf("%s", prompt);
        scanf("%lf", &probability);

        // Check if the input is a valid probability (between 0 and 1)
        if (probability >= 0.0 && probability <= 1.0) {
            valid = true;
        } else {
            printf("Invalid input. Please enter a probability between 0 and 1.\n");
        }
    }

    return probability;
}

// Function to calculate conditional probability using Bayes' Theorem
double calculateBayesTheorem(double pB_given_A, double pA, double pB) {
    if (pB == 0) {
        printf("Error: Probability of event B cannot be zero.\n");
        return -1; // Return an error code
    }
    return (pB_given_A * pA) / pB;
}

// Function to display the result
void displayResult(double result) {
    if (result >= 0) {
        printf("The probability P(A|B) is: %.4f\n", result);
    }
}

int main() {
    double pB_given_A, pA, pB, pA_given_B;
    char choice;

    do {
        // Get the probability of event B given A (P(B|A))
        pB_given_A = getValidProbability("Enter the probability of event B given A (P(B|A)): ");

        // Get the prior probability of event A (P(A))
        pA = getValidProbability("Enter the prior probability of event A (P(A)): ");

        // Get the total probability of event B (P(B))
        pB = getValidProbability("Enter the total probability of event B (P(B)): ");

        // Calculate the conditional probability P(A|B) using Bayes' Theorem
        pA_given_B = calculateBayesTheorem(pB_given_A, pA, pB);

        // If no error in calculation, display the result
        displayResult(pA_given_B);

        // Ask if the user wants to perform another calculation
        printf("Would you like to calculate another probability using Bayes' Theorem? (y/n): ");
        scanf(" %c", &choice);  // Adding a space before %c to catch any previous newline character

    } while (choice == 'y' || choice == 'Y');  // Repeat if the user enters 'y' or 'Y'

    printf("Thank you for using the Bayes' Theorem calculator. Goodbye!\n");
    return 0;
}