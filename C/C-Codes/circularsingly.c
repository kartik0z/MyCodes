#include <stdio.h>
#include <stdlib.h>

// Node structure with typedef
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted at beginning: %d\n", value);
}

void insertAtEnd(int value) {
    Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted at end: %d\n", value);
}

void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node *newNode = createNode(value);
    Node *temp = head;
    for (int i = 1; temp->next != head && i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted at position %d: %d\n", position, value);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    Node *toDelete = head;
    if (head->next == head) {
        head = NULL;
    } else {
        temp->next = head->next;
        head = head->next;
    }
    free(toDelete);
    printf("Deleted from beginning\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(temp);
    }
    printf("Deleted from end\n");
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    Node *temp = head, *prev = NULL;
    for (int i = 1; temp->next != head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == head && position > 1) {
        deleteAtEnd();
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Deleted from position %d\n", position);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice, value, position;
    while (1) {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
