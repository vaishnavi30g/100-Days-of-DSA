#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int V;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front > rear;
}

void kahnTopologicalSort() {
    // 1. Calculate In-degree of every vertex
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    // 2. Enqueue all vertices with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;
    int result[MAX];

    // 3. Process the queue
    while (!isEmpty()) {
        int u = dequeue();
        result[count++] = u;

        // Iterate through neighbors
        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                indegree[v]--; // Decrease indegree
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // 4. Check for cycles and print
    if (count != V) {
        printf("Graph contains a cycle! Topological sort not possible.\n");
    } else {
        printf("Topological Order (Kahn's): ");
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}

int main() {
    V = 6;
    // Example Graph: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    kahnTopologicalSort();

    return 0;
}
