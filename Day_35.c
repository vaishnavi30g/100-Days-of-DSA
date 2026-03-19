/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

// Function to initialize the queue
void initQueue(struct Queue *q, int n) {
    q->capacity = n;
    q->arr = (int *)malloc(n * sizeof(int)); // Dynamic allocation
    q->front = 0;
    q->rear = -1;
}

// Function to add an element
void enqueue(struct Queue *q, int value) {
    if (q->rear < q->capacity - 1) {
        q->arr[++(q->rear)] = value;
    }
}

// Function to display the queue
void display(struct Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d%s", q->arr[i], (i == q->rear ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, val;

    // Get number of elements
    if (scanf("%d", &n) != 1) return 0;

    struct Queue q;
    initQueue(&q, n);

    // Enqueue all elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Output the queue
    display(&q);

    // Clean up memory
    free(q.arr);

    return 0;
}
