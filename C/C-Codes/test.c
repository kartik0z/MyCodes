#include <stdio.h>

struct Student {
    char name[50];
    int marks[5];
};

int main() {
    struct Student students[3];
    int i, j;

    // Input details of students
    for(i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of 5 subjects for %s:\n", students[i].name);
        for(j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Display details of students
    for(i = 0; i < 3; i++) {
        printf("\nStudent: %s\n", students[i].name);
        printf("Marks: ");
        for(j = 0; j < 5; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}