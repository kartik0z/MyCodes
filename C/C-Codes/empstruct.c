#include <stdio.h>

// Define a structure to hold employee information
struct Employee {
    char name[50];
    int id;
    float basicSalary;
    float grossSalary;
};

// Function to calculate the gross salary
void calculateGrossSalary(struct Employee *emp) {
    emp->grossSalary = emp->basicSalary + (emp->basicSalary * 0.15);  // Assuming HRA + DA is 15% of basic salary
}

int main() {
    struct Employee emp;

    // Input employee details
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter basic salary: ");
    scanf("%f", &emp.basicSalary);

    // Calculate the gross salary
    calculateGrossSalary(&emp);

    // Display the employee details and gross salary
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("ID: %d\n", emp.id);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("Gross Salary: %.2f\n", emp.grossSalary);

    return 0;
}