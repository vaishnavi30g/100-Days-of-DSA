/*Problem: Count Nodes in Linked List

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
    int data;
    struct Node* next;
};
int main() {
    int n, value;
    int count = 0;
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
  temp = head;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
  printf("%d",count);

    return 0;
}
