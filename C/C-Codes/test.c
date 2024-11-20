#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayStudents();

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

    do {
        printf("Enter student name: ");
        fgets(name, sizeof(name), stdin); // Read the name with spaces
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0'; // Remove newline character if present
        }

        printf("Enter student age: ");
        scanf("%d", &age);
        getchar(); // Clear the newline left by scanf

        printf("Enter student grade: ");
        fgets(grade, sizeof(grade), stdin); // Read the grade with spaces
        if (grade[strlen(grade) - 1] == '\n') {
            grade[strlen(grade) - 1] = '\0'; // Remove newline character if present
        }

        fprintf(file, "%-30s %-5d %-10s\n", name, age, grade);

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &more);
        getchar(); // Clear the newline left by scanf

    } while (more == 'y' || more == 'Y');

    fclose(file);
    printf("Student information saved successfully to 'students.txt'.\n");

    // Display students in tabular format
    displayStudents();

    return 0;
}

void displayStudents() {
    FILE *file = fopen("students.txt", "r"); // Open file in read mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];
    printf("\n%-30s %-5s %-10s\n", "Name", "Age", "Grade");
    printf("----------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // Print each line as is (already formatted)
    }

    fclose(file);
}
