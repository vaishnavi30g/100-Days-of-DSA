/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Comparison function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0, res_r = n - 1;

    // 2. Two-pointer walk
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if current sum is closer to zero than the previous minimum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        if (sum < 0) {
            left++; // Need a bigger number
        } else if (sum > 0) {
            right--; // Need a smaller number
        } else {
            break; // Sum is 0, can't get closer than that
        }
    }

    // 3. Output the result pair
    printf("%d %d\n", arr[res_l], arr[res_r]);

    return 0;
}
