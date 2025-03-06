#include <stdio.h>

#define MAX 100  // Maximum stack size

struct Stack {
    int top;
    int a[MAX];  // Fixed-size array
};

// Function to initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top >= MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top < 0;
}

// Function to push an element
void push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", x);
        return;
    }
    stack->a[++stack->top] = x;
    printf("Pushed: %d\n", x);
}

// Function to pop an element
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("Popped: %d\n", stack->a[stack->top--]);
}

// Function to peek at the top element
void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack->a[stack->top]);
}

// Function to display all elements in stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->a[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
