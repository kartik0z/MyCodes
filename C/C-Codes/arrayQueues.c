#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear, size;
    int array[MAX_SIZE];
};

void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0; 
    }
    queue->rear++;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    queue->size--;
    if (queue->size == 0) {
        queue->front = -1;
        queue->rear = -1;
    }
    printf("%d dequeued from queue\n", item);
    return item;
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Front");
        printf("\n4. Display Rear");
        printf("\n5. Display Queue");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printf("Front item is: %d\n", front(&queue));
                break;
            case 4:
                printf("Rear item is: %d\n", rear(&queue));
                break;
            case 5:
                displayQueue(&queue);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
