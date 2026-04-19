/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int adj[MAX][MAX];
int visited[MAX];
int key[MAX];

int findMinKey() {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST() {
    // Initialize all keys as infinite and visited as false
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Always include first 1st vertex in MST.
    key[1] = 0; 
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included
        int u = findMinKey();

        // Add the picked vertex to the MST Set
        visited[u] = 1;
        total_weight += key[u];

        // Update key value of the adjacent vertices of the picked vertex
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && visited[v] == 0 && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", total_weight);
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency matrix with 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges and weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // Undirected graph
    }

    primMST();

    return 0;
}
