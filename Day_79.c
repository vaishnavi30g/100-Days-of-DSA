/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent a neighbor in the adjacency list
typedef struct Node {
    int v, weight;
    struct Node* next;
} Node;

// Structure for the Min-Heap elements
typedef struct {
    int v, dist;
} HeapNode;

// Structure for the Priority Queue
typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

// Function to create a new graph node
Node* createNode(int v, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Min-Heap Functions
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->data[i].v = v;
    heap->data[i].dist = dist;
    while (i != 0 && heap->data[i].dist < heap->data[(i - 1) / 2].dist) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int smallest = 2 * i + 1;
        if (2 * i + 2 < heap->size && heap->data[2 * i + 2].dist < heap->data[smallest].dist)
            smallest = 2 * i + 2;
        if (heap->data[i].dist <= heap->data[smallest].dist) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return root;
}

// Main Dijkstra Function
void dijkstra(int n, Node** adj, int source) {
    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INF;

    MinHeap* pq = createHeap(n * n); // Capacity for worst case
    dist[source] = 0;
    push(pq, source, 0);

    while (pq->size > 0) {
        HeapNode top = pop(pq);
        int u = top.v;
        int d = top.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            int weight = temp->weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("-1 ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    free(dist);
    free(pq->data);
    free(pq);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Assuming directed graph based on input style; 
        // for undirected, add edge from v to u as well.
        Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, adj, source);

    return 0;
}
