/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int heapSize = 0;

// Helper to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the element at index i up to its correct position
void bubbleUp(int i) {
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

// Moves the element at index i down to its correct position
void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

// Insertion operation: O(log N)
void insert(int x) {
    if (heapSize == MAX_SIZE) return;
    
    heap[heapSize] = x;
    bubbleUp(heapSize);
    heapSize++;
}

// Extraction operation: O(log N)
int extractMin() {
    if (heapSize <= 0) return -1;
    
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    minHeapify(0);
    
    return root;
}

// Peek operation: O(1)
int peek() {
    if (heapSize <= 0) return -1;
    return heap[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char command[20];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } 
        else if (strcmp(command, "extractMin") == 0) {
            int result = extractMin();
            if (result == -1) printf("-1\n");
            else printf("%d\n", result);
        } 
        else if (strcmp(command, "peek") == 0) {
            int result = peek();
            if (result == -1) printf("-1\n");
            else printf("%d\n", result);
        }
    }

    return 0;
}
