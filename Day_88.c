/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.*/

#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting stall positions
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if it is possible to place k cows 
// with at least 'min_dist' distance apart
int canPlaceCows(int stalls[], int n, int k, int min_dist) {
    int count = 1; // Place the first cow in the first stall
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= min_dist) {
            count++;
            last_pos = stalls[i];
            if (count >= k) return 1; // All cows placed successfully
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *stalls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search on the answer (distance)
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;     // This distance works, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Distance too large, try smaller
        }
    }

    printf("%d\n", ans);

    free(stalls);
    return 0;
}
