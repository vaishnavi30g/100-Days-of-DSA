/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* deleteFirstOccurrence(struct node* head, int key) {
    // Scenario 1: Empty list
    if (head == NULL) return NULL;

    // Scenario 2: Key is at the head
    if (head->data == key) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Scenario 3: Key is further down the list
    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If key was found, remove it
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }

    return head;
}

// Function to build and print omitted for brevity; 
// ensure you call this logic after input collection.
