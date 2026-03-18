/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* exp) {
    int i, k;
    int n = strlen(exp);
    char stack[100];
    int top = -1;

    for (i = 0; i < n; i++) {
        // 1. If the character is an operand, print it
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        // 2. If '(', push to stack
        else if (exp[i] == '(') {
            stack[++top] = exp[i];
        }
        // 3. If ')', pop and print until '(' is found
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--; // Pop '('
        }
        // 4. If an operator is encountered
        else {
            while (top != -1 && precedence(exp[i]) <= precedence(stack[top])) {
                printf("%c", stack[top--]);
            }
            stack[++top] = exp[i];
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char exp[100];
    // Use scanf or fgets to read the infix expression
    if (scanf("%s", exp) == 1) {
        infixToPostfix(exp);
    }
    return 0;
}
