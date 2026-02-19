/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include<stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int n,k;
    printf("Enter number for elements in array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter a position by which you want to rotate array");
    scanf("%d",&k);
    for(int i = 0;i<n;i++){
        
    }
    k = k % n;

    // Step 1: Reverse the whole array
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse the first k elements
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse the rest
    reverse(arr, k, n - 1);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    return 0;
}
