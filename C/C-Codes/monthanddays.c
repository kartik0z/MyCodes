#include <stdio.h>

int main() {
    int totalDays, months, days;

    printf("Enter the total number of days: ");
    scanf("%d", &totalDays);

    months = totalDays / 30;
    days = totalDays % 30;

    printf("\nMonths: %d", months);
    printf("\nDays: %d", days);

    return 0;
}