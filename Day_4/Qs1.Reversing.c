/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/
#include<stdio.h>

int main()
{
    int n,temp;
    printf("Enter the number of elements for an array\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        printf("Enter the element\n");
        scanf("%d",&arr[i]);
    }
    int *start = arr;          
    int *end = arr + (n - 1);
    while(start < end) {
        // Swapping values at the pointer addresses
        temp = *start;
        *start = *end;
        *end = temp;

        // Moving pointers toward the middle
        start++;
        end--;
    }

    printf("Updated array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }  
    return 0;
}
