/*Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to ensure the array is sorted
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Iterative Binary Search function
// Returns the index of target if found, otherwise returns -1
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, target;
    
    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Binary Search requires a sorted array
    qsort(arr, n, sizeof(int), compare);

    // For the sake of your example output, we print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }

    /* 
       Note: If you wanted to search for a specific value, 
       you would call binarySearch(arr, n, target) here.
    */

    free(arr);
    return 0;
}
