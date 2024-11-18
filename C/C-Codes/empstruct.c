#include <stdio.h>

struct Employee {
    char name[50];
    float basicPay, netSalary;
};

int main() {
    struct Employee emp[5];

    // Input details for 5 employees
    for (int i = 0; i < 5; i++) {
        printf("Enter Employee %d Name: ", i + 1);
        scanf("%s", emp[i].name);
        printf("Enter Basic Pay for %s: ", emp[i].name);
        scanf("%f", &emp[i].basicPay);

        // Calculate net salary (20% allowance, 10% deduction)
        emp[i].netSalary = emp[i].basicPay * 1.10;
    }

    // Display details of all employees
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Employee %d: %s\n", i + 1, emp[i].name);
        printf("Net Salary: %.2f\n", emp[i].netSalary);
    }

    return 0;
}
