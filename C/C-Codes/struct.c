#include <stdio.h>

// Structure to hold student information
struct Student {
    char name[50];
    int roll_no;
    float marks[5]; // Array to store marks for 5 subjects
};

int main() {
    struct Student student; // Declare a student structure
    float total = 0.0, average;

    // Input student details
    printf("Enter the student's name: ");
    fgets(student.name, sizeof(student.name), stdin);

    printf("Enter the roll number: ");
    scanf("%d", &student.roll_no);

    // Input marks for 5 subjects
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.marks[i]);
        total += student.marks[i];
    }

    // Calculate average
    average = total / 5;

    // Display student details
    printf("\nStudent Details:\n");
    printf("Name: %s", student.name);
    printf("Roll Number: %d\n", student.roll_no);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student.marks[i]);
    }
    printf("\nTotal Marks: %.2f\n", total);
    printf("Average Marks: %.2f\n", average);

    return 0;
}