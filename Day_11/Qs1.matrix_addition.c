/*
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9*/
#include<stdio.h>

int main()
{
    int i,j,m,n;
    printf("Enter the value for rows and columns of matrices\n");
    scanf("%d %d",&m,&n);
    int A[m][n],B[m][n];
printf("Enter the values for first matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter value at [%d] [%d]\n",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n");
    printf("Enter values for second matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter value at [%d] [%d]\n",i,j);
            scanf("%d",&B[i][j]);
        }
    }

    // Printing both matrices same way
    printf("\n");
    printf("First Matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Second Matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Solution after addition\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",A[i][j]+B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
