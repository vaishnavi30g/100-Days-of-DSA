/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
  char str[20];
  fgets(str,20,stdin);
  str[strcspn(str,"\n")] = '\0';
  int l = strlen(str);

  bool flag = true;
  int left = 0;
  int right = l-1;
  while(left<right){
    if(str[left] != str[right]){
        flag = false;
        break;
    }
    left++;
    right--;
  }
  if(flag){
    printf("The string is palindrome\n");
  }
  else{
    printf("The string is not palindrome\n");
  }
  return 0;
  
}
