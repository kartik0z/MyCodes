#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
    char grade;
    char status[10];
};

// Function to calculate grade based on marks
char calculate_grade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 50) return 'C';
    else if (marks >= 40) return 'D';
    else return 'F';
}

// Function to determine pass/fail status
void calculate_status(float marks, char *status) {
    if (marks >= 40)
        strcpy(status, "Pass");
    else
        strcpy(status, "Fail");
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        getchar(); // Clear the newline character left in the input buffer
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove trailing newline
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        // Calculate grade and pass/fail status
        students[i].grade = calculate_grade(students[i].marks);
        calculate_status(students[i].marks, students[i].status);
    }

    // Display results
    printf("\nStudent Results:\n");
    printf("-----------------------------------------------------\n");
    printf("Roll No\tName\t\tMarks\tGrade\tStatus\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%.2f\t%c\t%s\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks,
               students[i].grade,
               students[i].status);
    }

    return 0;
}
