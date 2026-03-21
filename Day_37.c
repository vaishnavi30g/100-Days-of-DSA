/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble up to maintain Min-Heap property
void insert(int val) {
    if (size >= MAX) return;
    
    heap[size] = val;
    int current = size;
    size++;
    
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Bubble down to maintain Min-Heap property
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    
    int i = 0;
    while (2 * i + 1 < size) {
        int smallest = 2 * i + 1; // Left child
        int right = 2 * i + 2;
        
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (heap[i] <= heap[smallest]) break;
        
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char op[10];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    
    return 0;
}
