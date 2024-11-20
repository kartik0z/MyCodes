#include <stdio.h>

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
        scanf(" %[^\n]s", name); // Read string with spaces

        printf("Enter student age: ");
        scanf("%d", &age);

        printf("Enter student grade: ");
        scanf(" %[^\n]s", grade); // Read string with spaces

        fprintf(file, "Name: %s, Age: %d, Grade: %s\n", name, age, grade);

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    fclose(file);
    printf("Student information saved successfully to 'students.txt'.\n");

    return 0;
}