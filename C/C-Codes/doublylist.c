#include <stdio.h>
#include <stdlib.h>

// Typedef for Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void insertAtPosition(Node **head, int data, int position);
void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteFromPosition(Node **head, int position);
void displayList(Node *head);
void searchList(Node *head, int key);

int main() {
    Node *head = NULL;
    int choice, value, position;

    while (1) {
        // Menu
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from a Position\n");
        printf("7. Display List\n");
        printf("8. Search in List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchList(head, value);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at the end.\n");
}

// Function to insert at a specific position
void insertAtPosition(Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted at position %d.\n", position);
}

// Function to delete from the beginning of the list
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end of the list
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node *temp = *head;

    if (temp->next == NULL) { // Only one node
        *head = NULL;
        free(temp);
        printf("Node deleted from the end.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete from a specific position
void deleteFromPosition(Node **head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or list is empty!\n");
        return;
    }

    Node *temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// Function to display the list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
void searchList(Node *head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value %d not found in the list.\n", key);
}