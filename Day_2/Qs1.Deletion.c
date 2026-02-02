/*
  Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/
#include<stdio.h>

int main()
{
    int n,x;
    printf("Enter the number of elements for an array\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=1;i<=n;i++){
        printf("Enter the element\n");
        scanf("%d",&arr[i]);
    }
    printf("Enter the position of what you want to delete the element\n");
    scanf("%d",&x);
    for(int i = x;i<n;i++){
        arr[i] = arr[i+1];
        n--;
    }
    printf("Updated array: ");
    for (int j = 1; j <= n; j++) {
        printf("%d ", arr[j]);
    }  
    return 0;
}
