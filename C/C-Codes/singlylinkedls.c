#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createLinkedlist(int n) {
    int i;
    node *head = NULL, *temp = NULL, *p = NULL;

    for (i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}

void insert_At_Beginning(node **head, int value) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void insert_At_End(node **head, int value) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
}

void insert_At_Position(node **head, int value, int pos) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;

    if (pos == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }

    node *p = *head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Invalid position!\n");
        free(temp);
        return;
    }

    temp->next = p->next;
    p->next = temp;
}

void displayList(node *head) {
    node *p = head;
    printf("\nLinked List: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int n, choice, value, pos;
    node *HEAD = NULL;

    printf("How many nodes: ");
    scanf("%d", &n);
    HEAD = createLinkedlist(n);
    displayList(HEAD);

    while (1) {
        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_At_Beginning(&HEAD, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_At_End(&HEAD, value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insert_At_Position(&HEAD, value, pos);
                break;

            case 4:
                displayList(HEAD);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
