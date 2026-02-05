/*
Problem: A system receives two separate logs of user arrival times from two different servers.
Each log is already sorted in ascending order.
Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs
and append the earlier one to the final log until all entries are processed
*/
#include <stdio.h>

int main() {
    int p, q, total;
    
    // 1. Input for Server 1
    printf("Enter size of log 1: ");
    scanf("%d", &p);
    int a[p];
    for (int i = 0; i < p; i++) scanf("%d", &a[i]);

    // 2. Input for Server 2
    printf("Enter size of log 2: ");
    scanf("%d", &q);
    int b[q];
    for (int i = 0; i < q; i++) scanf("%d", &b[i]);

    // 3. Create Master Log and Merge
    total = p + q;
    int master[total];
    
    for (int i = 0; i < p; i++) {
        master[i] = a[i];
    }
    for (int i = 0; i < q; i++) {
        master[p + i] = b[i]; // Starts filling after the first p elements
    }

    // 4. Sorting the Master Log (Bubble Sort)
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (master[j] > master[j + 1]) {
                // Swap
                int temp = master[j];
                master[j] = master[j + 1];
                master[j + 1] = temp;
            }
        }
    }

    // 5. Output
    printf("\nFinal Chronological Log:\n");
    for (int i = 0; i < total; i++) {
        printf("%d ", master[i]);
    }
    printf("\n");

    return 0;
}
