/* 
  Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include<stdio.h>

int main()
{
    int n,x,y;
    int arr[50];
    printf("Enter the number of elements for an array\n");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("Enter the element\n");
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to insert in Array\n");
    scanf("%d",&x);
    printf("At what position you want to insert in array(0 to %d): ", n);
    scanf("%d",&y);
    for (int j = n - 1; j >= y; j--) {
    arr[j + 1] = arr[j];
}
    arr[y]=x;
    n++;
    
    printf("Updated array\n");
    for(int j=0;j<n;j++){
        printf("%d\t",arr[j]);
    }
    return 0;
    
}
