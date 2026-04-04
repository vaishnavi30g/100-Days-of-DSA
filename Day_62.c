/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a neighbor in the list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge
void addEdge(struct Graph* graph, int u, int v, int is_directed) {
    // Add edge from u to v
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    // If undirected, add edge from v to u
    if (!is_directed) {
        newNode = createNode(u);
        newNode->next = graph->adjLists[v];
        graph->adjLists[v] = newNode;
    }
}

int main() {
    int n, m, u, v, is_directed;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Directed? (1 for Yes, 0 for No): ");
    scanf("%d", &is_directed);

    // Initialize Graph
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }

    // Input edges
    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, is_directed);
    }

    // Output the Adjacency List
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < n; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
