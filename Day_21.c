/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* next;
};
int main()
{
  int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // 1. Get the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        // Create a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;

        // 2. Link the nodes
        if (head == NULL) {
            head = newNode; // First node becomes the head
            temp = head;
        } else {
            temp->next = newNode; // Link previous node to new node
            temp = temp->next;    // Move temp to the end
        }
    }

    // 3. Traverse and Print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
}
