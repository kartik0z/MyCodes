#include <stdio.h>
#include <string.h>

// Define structure
struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    // Declare a structure variable
    struct Person person1;
    
    // Assign values
    strcpy(person1.name, "Alice");
    person1.age = 30;
    person1.salary = 50000.50;
    
    // Access members
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Salary: %.2f\n", person1.salary);

    return 0;
}
