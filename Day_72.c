/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

char findFirstRepeated(char* s) {
    // Array to keep track of visited characters
    // Using 256 to cover all possible ASCII characters
    int visited[MAX_CHAR] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = s[i];

        // If the character is already visited, this is the 
        // first "second occurrence" we've hit.
        if (visited[val] == 1) {
            return s[i];
        }

        // Mark character as visited
        visited[val] = 1;
    }

    // No repeated character found
    return '\0';
}

int main() {
    char s[100001]; // Adjust size based on expected input constraints
    if (scanf("%s", s) != 1) return 0;

    char result = findFirstRepeated(s);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}
