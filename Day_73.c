/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

char firstNonRepeating(char* s) {
    int count[MAX_CHAR] = {0};
    int len = strlen(s);

    // Pass 1: Count frequency of each character
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    // Pass 2: Find the first character with count 1
    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    if (scanf("%s", s) != 1) return 0;

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}
