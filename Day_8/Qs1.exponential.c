/* 
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/
#include<stdio.h>

int expo(int n,int m){
    if(m==0){
        return 1;
    }
    return n*expo(n,m-1);
}
int main()
{
   int n,m;
   printf("Enter the number and its exponential digit\n");
   scanf("%d %d",&n,&m);
   printf("%d",expo(n,m));
   return 0;
}
