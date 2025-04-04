#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, choice, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Edge\n2. Print Graph\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
                    printf("Invalid vertices!\n");
                } else {
                    addEdge(graph, src, dest);
                    printf("Edge added successfully.\n");
                }
                break;
            
            case 2:
                printGraph(graph);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
