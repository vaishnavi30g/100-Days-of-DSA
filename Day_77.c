/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>

int adj[100][100];
int visited[100];
int n, m;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        // If there is an edge and the node hasn't been visited
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Start DFS from the first node
    dfs(1);

    // Check if all nodes were visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
