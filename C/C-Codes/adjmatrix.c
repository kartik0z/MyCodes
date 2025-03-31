#include <stdio.h>

#define MAX 5

void initializeMatrix(int matrix[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void inputEdges(int matrix[MAX][MAX], int vertices, int edges) {
    int src, dest;
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge! Vertices should be between 0 and %d\n", vertices - 1);
            i--;
        } else {
            matrix[src][dest] = 1;
            matrix[dest][src] = 1; // For undirected graph
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[MAX][MAX];
    int vertices, edges;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Initialize Matrix\n");
        printf("2. Input Edges\n");
        printf("3. Print Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices (up to %d): ", MAX);
                scanf("%d", &vertices);
                if (vertices > MAX || vertices <= 0) {
                    printf("Invalid number of vertices!\n");
                } else {
                    initializeMatrix(adjMatrix, vertices);
                    printf("Matrix initialized successfully.\n");
                }
                break;

            case 2:
                if (vertices <= 0) {
                    printf("Please initialize the matrix first.\n");
                    break;
                }
                printf("Enter the number of edges: ");
                scanf("%d", &edges);
                if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
                    printf("Invalid number of edges!\n");
                } else {
                    inputEdges(adjMatrix, vertices, edges);
                    printf("Edges added successfully.\n");
                }
                break;

            case 3:
                if (vertices <= 0) {
                    printf("Please initialize the matrix first.\n");
                    break;
                }
                printMatrix(adjMatrix, vertices);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}