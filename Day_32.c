/* Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000  // Define a maximum size for the stack

int main() {
    int n, m;
    int stack[MAX_SIZE];
    int top = -1; // Stack is initially empty

    // 1. Read the number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // 2. Push n integers onto the stack
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (top < MAX_SIZE - 1) {
            stack[++top] = val; // Increment top and then insert
        }
    }

    // 3. Read the number of pops
    if (scanf("%d", &m) != 1) return 0;

    // 4. Perform m pop operations
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--; // Simply decrementing top effectively "pops" the element
        }
    }

    // 5. Print remaining elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" "); // Print space between elements, but not after the last one
        }
    }
    printf("\n");

    return 0;
}
