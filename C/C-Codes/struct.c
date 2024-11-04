#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    struct Student student1;

    // Assign values to structure members
    student1.roll_no = 101;
    strcpy(student1.name, "Alice");
    student1.marks = 95.5;

    // Print structure members
    printf("Student Roll No: %d\n", student1.roll_no);
    printf("Student Name: %s\n", student1.name);
    printf("Student Marks: %.2f\n", student1.marks);

    return 0;
}
