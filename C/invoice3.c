#include <stdio.h>

int main() {
    int choice, quantity, totalCost = 0;
    int prices[] = {10, 8, 12, 10, 13, 14}; // Prices of items

    do {
        printf("\n-------<STATIONARY LIST>-------");
        printf("\n1. Pencil - Rs.10");
        printf("\n2. Eraser - Rs.8");
        printf("\n3. Sharpener - Rs.12");
        printf("\n4. Compass - Rs.10");
        printf("\n5. Files - Rs.13");
        printf("\n6. Fevicol - Rs.14");
        printf("\n7. Checkout");
        printf("\n------------------------------");

        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            printf("\nEnter the quantity: ");
            scanf("%d", &quantity);

            totalCost += prices[choice - 1] * quantity;
            printf("\nAdded to your order! Current total: Rs.%d", totalCost);
        } else if (choice == 7) {
            printf("\nProceeding to checkout...");
        } else {
            printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 7);

    // Display final total
    printf("\n-----<BILL>-----");
    printf("\nTotal Amount Due: Rs.%d", totalCost);
    printf("\n------------------------------");

    return 0;
}