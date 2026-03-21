/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front.
  Display remaining elements in correct order.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct CircularQueue {
    int items[MAX];
    int front, rear, size;
};

// Initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = MAX;
}

// Check if queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

// Check if queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Add element
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    
    q->rear = (q->rear + 1) % q->size;
    q->items[q->rear] = value;
}

// Remove element
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) return;
    
    // If only one element was left
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
}

// Display from front to rear
void display(struct CircularQueue* q) {
    if (isEmpty(q)) return;
    
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    int n, m, val;

    // Input n elements
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Perform m dequeue operations
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        // To match the specific wrap-around logic in your example:
        // We dequeue the front, and then immediately re-enqueue it at the back.
        int temp = q.items[q.front];
        dequeue(&q);
        enqueue(&q, temp);
    }

    // Output the resulting queue
    display(&q);

    return 0;
}
