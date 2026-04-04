/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited; // Array to keep track of visited nodes
};

// DFS Recursive Function
void DFS(struct Graph* graph, int vertex) {
    // 1. Mark the current node as visited
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // 2. Traverse all adjacent vertices
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        // 3. If neighbor isn't visited, recurse
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Helper to create a node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, u, v, startVertex;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize Graph
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node*));
    graph->visited = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize all as unvisited
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        // Assuming undirected for this example
        struct Node* newNode = createNode(v);
        newNode->next = graph->adjLists[u];
        graph->adjLists[u] = newNode;

        newNode = createNode(u);
        newNode->next = graph->adjLists[v];
        graph->adjLists[v] = newNode;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(graph, startVertex);
    printf("\n");

    return 0;
}
