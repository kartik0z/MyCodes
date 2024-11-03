#include <stdio.h>

// Function to display the menu
void displayMenu() {
    printf("------- Pizza Hut Menu -------\n");
    printf("1. Margherita - $10\n");
    printf("2. Mushroom - $8\n");
    printf("3. BBQ Chicken - $12\n");
    printf("4. Veggie Supreme - $10\n");
    printf("5. Hawaiian Cheese - $13\n");
    printf("6. Cheese Lovers - $14\n");
    printf("7. Checkout\n");
    printf("------------------------------\n");
}

// Function to get the price of the selected item
int getItemPrice(int choice) {
    switch (choice) {
        case 1: return 10; 
        case 2: return 8;  
        case 3: return 12; 
        case 4: return 10; 
        case 5: return 13; 
        case 6: return 14; 
        default: return 0; 
    }
}

int main() {
    int choice, quantity, totalCost = 0;

    do {
        displayMenu(); // Display the menu each time in the loop

        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {  // Valid choices
            int itemPrice = getItemPrice(choice);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            
            totalCost += itemPrice * quantity;
            printf("Added to your order! Current total: $%d\n", totalCost);
        } else if (choice == 7) {  // Checkout
            printf("\nProceeding to checkout...\n");
        } else {  // Invalid choice
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7); // Continue until choice is 'Checkout'

    // Display final invoice
    printf("\n----- Pizza Hut Invoice -----\n");
    printf("Total Amount Due: $%d\n", totalCost);
    printf("------------------------------\n");

    return 0;
}