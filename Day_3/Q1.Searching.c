/* Problem: Implement linear search to find key k in an array.
 Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/

#include<stdio.h>

int main()
{
    int n,x,found,j;
    scanf("%d",&n); // define the no. of elements
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);   // To enter n elements with for loop
    }
    printf("\n");
    scanf("%d",&x); // define the element to get the index
    for( j = 0 ; j<n ; j++){
        found = -1;
        if(arr[j] == x){
            found = j;
            break;
        }
    }
    if(found != -1){
        printf("Found at index %d\n",j);
        printf("Comparisons %d\n",j+1);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
