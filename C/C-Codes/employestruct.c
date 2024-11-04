#include <stdio.h>

// Define the structure for Employee
struct Employee {
    int id;
    char name[50];
    float basicPay;
    float allowance;
    float deduction;
    float netSalary;
};

// Function to calculate net salary
void calculateNetSalary(struct Employee *emp) {
    // Calculate allowance based on basic pay
    if (emp->basicPay < 20000) {
        emp->allowance = emp->basicPay * 0.20;  // 20% of basic pay
    } else if (emp->basicPay >= 20000 && emp->basicPay <= 50000) {
        emp->allowance = emp->basicPay * 0.25;  // 25% of basic pay
    } else {
        emp->allowance = emp->basicPay * 0.30;  // 30% of basic pay
    }

    // Calculate deduction based on basic pay
    if (emp->basicPay < 20000) {
        emp->deduction = emp->basicPay * 0.10;  // 10% of basic pay
    } else if (emp->basicPay >= 20000 && emp->basicPay <= 50000) {
        emp->deduction = emp->basicPay * 0.15;  // 15% of basic pay
    } else {
        emp->deduction = emp->basicPay * 0.20;  // 20% of basic pay
    }

    // Calculate net salary
    emp->netSalary = emp->basicPay + emp->allowance - emp->deduction;
}

// Main function
int main() {
    struct Employee emp;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Basic Pay: ");
    scanf("%f", &emp.basicPay);

    // Calculate net salary
    calculateNetSalary(&emp);

    // Display employee details
    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Basic Pay: %.2f\n", emp.basicPay);
    printf("Allowance: %.2f\n", emp.allowance);
    printf("Deduction: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", emp.netSalary);

    return 0;
}