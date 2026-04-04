/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, u, v, i, j;
    int is_directed;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &is_directed);

    // 1. Dynamically allocate n x n matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int)); // calloc initializes to 0
    }

    // 2. Input edges
    printf("Enter %d pairs of vertices (0 to %d):\n", m, n - 1);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        // Basic bounds checking
        if (u >= 0 && u < n && v >= 0 && v < n) {
            matrix[u][v] = 1;
            if (!is_directed) {
                matrix[v][u] = 1;
            }
        } else {
            printf("Invalid edge! Try again.\n");
            i--; // Repeat this iteration
        }
    }

    // 3. Print the matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 4. Free memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
