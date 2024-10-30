#include <stdio.h>

int main() {
    int choice, quantity, totalCost = 0;

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

            switch (choice) {
                case 1: totalCost += 10 * quantity; break;
                case 2: totalCost += 8 * quantity; break;
                case 3: totalCost += 12 * quantity; break;
                case 4: totalCost += 10 * quantity; break;
                case 5: totalCost += 13 * quantity; break;
                case 6: totalCost += 14 * quantity; break;
            }

            printf("\nAdded to your order! Current total: %d", totalCost);
        } else if (choice == 7) {
            printf("\nProceeding to checkout...");
        } else {
            printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 7); // Continue until choice is 'Checkout'

    // Display final total
    printf("\n-----<BILL>-----");
    printf("\nTotal Amount Due: Rs.%d", totalCost);
    printf("\n------------------------------");

    return 0;
}