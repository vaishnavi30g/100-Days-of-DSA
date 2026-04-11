#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V, E;

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all vertices adjacent to this vertex
        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    // Initialize visited and recStack as false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i))
                return true;
        }
    }
    return false;
}

int main() {
    // Example: V=4, E=4
    // 0 -> 1, 1 -> 2, 2 -> 3, 3 -> 3 (Self loop)
    V = 4;
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][3] = 1; 

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
