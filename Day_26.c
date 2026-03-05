/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to add a node to the end of the DLL
void append(struct Node** head, struct Node** tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = *tail; // Set the new node's back pointer to the current tail

    if (*head == NULL) {
        // List is empty, this is the first node
        newNode->prev = NULL;
        *head = newNode;
    } else {
        // Update current tail to point forward to the new node
        (*tail)->next = newNode;
    }
    *tail = newNode; // Update tail to be the new node
}

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, &tail, value);
    }

    // Traverse and print forward
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
