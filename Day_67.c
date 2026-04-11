#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;
int V;

void push(int v) {
    stack[++top] = v;
}

void topologicalSortUtil(int v) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i);
        }
    }

    // Push vertex to stack after all its adjacent vertices are processed
    push(v);
}

void topologicalSort() {
    // Initialize visited array
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call recursive helper for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i);
        }
    }

    // Print contents of stack
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    V = 6; // Number of vertices

    // Example Graph Edges:
    // 5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort();

    return 0;
}
