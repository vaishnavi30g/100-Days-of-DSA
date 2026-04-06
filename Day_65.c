/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// DFS function to detect cycle
bool isCycleUtil(int u, bool visited[], int parent, struct Node* adj[]) {
    visited[u] = true;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;

        // If neighbor v is not visited, recurse for it
        if (!visited[v]) {
            if (isCycleUtil(v, visited, u, adj))
                return true;
        }
        // If v is visited and is NOT the parent of u, there's a cycle
        else if (v != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(int n, struct Node* adj[]) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    // Check all components (in case the graph is disconnected)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCycleUtil(i, visited, -1, adj))
                return true;
        }
    }
    return false;
}

// Helper to add edges (Undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int main() {
    int n = 4;
    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    // Example: A-B, B-C, C-A (A triangle cycle)
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (hasCycle(n, adj)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
