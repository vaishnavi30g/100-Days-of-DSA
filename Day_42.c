/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Stack Structure
int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

// Queue Structure
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    // Input: Fill the queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // Step 1: Queue -> Stack
    while (front < rear) {
        push(dequeue());
    }

    // Reset queue pointers to "empty" it for refilling
    front = 0;
    rear = 0;

    // Step 2: Stack -> Queue
    while (top != -1) {
        enqueue(pop());
    }

    // Output: Print reversed queue
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
