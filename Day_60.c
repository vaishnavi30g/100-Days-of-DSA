/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Logic:
 * For a node at index i:
 * Left Child is at 2*i + 1
 * Right Child is at 2*i + 2
 */

bool isMinHeap(int arr[], int n) {
    // We only need to check internal nodes
    // Last internal node is at index (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check Left Child
        if (arr[2 * i + 1] < arr[i]) {
            return false;
        }

        // Check Right Child (if it exists)
        if (2 * i + 2 < n) {
            if (arr[2 * i + 2] < arr[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}
