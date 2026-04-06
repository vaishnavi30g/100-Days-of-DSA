/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for an Adjacency List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to perform BFS
void bfs(int n, struct Node* adj[], int s) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    // Queue setup
    int queue[n];
    int front = 0, rear = 0;

    // Start with the source
    visited[s] = true;
    queue[rear++] = s;

    printf("BFS Traversal: ");

    while (front < rear) {
        // Dequeue
        int u = queue[front++];
        printf("%d ", u);

        // Traverse all neighbors of u
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Helper to add an edge to an undirected graph
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n = 5; // Number of vertices
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    // Example edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    bfs(n, adj, 0);

    return 0;
}
