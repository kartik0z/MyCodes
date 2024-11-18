#include <stdio.h>

// Define the structure for Employee
struct Employee {
    int id;
    char name[50];
    float basicPay;
    float allowance;
    float deduction;
};

int main() {
    struct Employee emp[5];

    // Input and process details for 5 employees
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Employee %d (ID, Name, Basic Pay): ", i + 1);
        scanf("%d %s %f", &emp[i].id, emp[i].name, &emp[i].basicPay);

        // Calculate allowance and deduction
        emp[i].allowance = emp[i].basicPay * (emp[i].basicPay < 20000 ? 0.20 : emp[i].basicPay <= 50000 ? 0.25 : 0.30);
        emp[i].deduction = emp[i].basicPay * (emp[i].basicPay < 20000 ? 0.10 : emp[i].basicPay <= 50000 ? 0.15 : 0.20);
    }

    // Display employee details
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Basic Pay: %.2f\n", emp[i].basicPay);
        printf("Allowance: %.2f\n", emp[i].allowance);
        printf("Deduction: %.2f\n", emp[i].deduction);
        printf("Net Salary: %.2f\n", emp[i].basicPay + emp[i].allowance - emp[i].deduction);
    }

    return 0;
}
