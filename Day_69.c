#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define INF INT_MAX

// A structure to represent a node in the priority queue
struct Node {
    int v;
    int dist;
};

// A structure to represent a Min-Heap
struct MinHeap {
    int size;
    struct Node array[V * V];
};

void swap(struct Node* a, struct Node* b) {
    struct Node t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].dist < minHeap->array[smallest].dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right].dist < minHeap->array[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct Node extractMin(struct MinHeap* minHeap) {
    struct Node root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

void insert(struct MinHeap* minHeap, int v, int dist) {
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i].v = v;
    minHeap->array[i].dist = dist;

    while (i && minHeap->array[i].dist < minHeap->array[(i - 1) / 2].dist) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    struct MinHeap minHeap = {0};

    for (int i = 0; i < V; i++) dist[i] = INF;

    dist[src] = 0;
    insert(&minHeap, src, 0);

    while (minHeap.size != 0) {
        struct Node minNode = extractMin(&minHeap);
        int u = minNode.v;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                insert(&minHeap, v, dist[v]);
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = { { 0, 10, 0, 0, 5 },
                        { 0, 0, 1, 0, 2 },
                        { 0, 0, 0, 4, 0 },
                        { 7, 0, 6, 0, 0 },
                        { 0, 3, 9, 2, 0 } };

    dijkstra(graph, 0);
    return 0;
}
