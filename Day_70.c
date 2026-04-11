#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];

    // 1. Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // 2. Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 3. Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5; // Total vertices
    int E = 8; // Total edges

    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, 
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}
