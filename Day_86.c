/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8

Input:
20

Output:
4

Input:
1

Output:
1

Explanation:
Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n.
If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half;
otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.*/

#include <stdio.h>

/**
 * Finds the integer square root using binary search.
 * We use long long for 'mid' and 'square' to prevent overflow 
 * when calculating mid * mid for large values of n.
 */
long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0;
    long long high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid; // Exact square root found
        } else if (square < n) {
            ans = mid;     // mid could be the answer, but check for larger
            low = mid + 1;
        } else {
            high = mid - 1; // Square is too big, look left
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 0) {
        // Square root of negative numbers is not defined in integers
        return 0;
    }

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}
