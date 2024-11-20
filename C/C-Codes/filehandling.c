#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("students.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char name[50];
    int age;
    char grade[10];
    char more;

    // Check if file is empty to add column headers only once
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) { // If file is empty
        fprintf(file, "%-30s %-10s %-10s\n", "Name", "Age", "Grade");
        fprintf(file, "---------------------------------------------\n");
    }

    do {
        printf("Enter student name: ");
        scanf(" %[^\n]s", name); // Read string with spaces

        printf("Enter student age: ");
        scanf("%d", &age);

        printf("Enter student grade: ");
        scanf(" %[^\n]s", grade); // Read string with spaces

        // Write the data in a tabular format
        fprintf(file, "%-30s %-10d %-10s\n", name, age, grade);

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    fclose(file);
    printf("Student information saved successfully to 'students.txt'.\n");

    return 0;
}