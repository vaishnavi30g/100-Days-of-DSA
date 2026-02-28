/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
}; // Added semicolon here

struct node* buildlist(int count) {
    struct node *head = NULL, *tail = NULL;
    for(int i = 0; i < count; i++) {
        int value;
        scanf("%d", &value);
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

struct node* mergeSortedLists(struct node* list1, struct node* list2) {
    // 1. The Dummy Node: A "fake" starting point
    struct node dummy; 
    dummy.next = NULL;
    struct node* tail = &dummy; 

    // 2. The Comparison Loop
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;    
            list1 = list1->next;   
        } else {
            tail->next = list2;    
            list2 = list2->next;   
        }
        tail = tail->next;         
    }

    // 3. The Final Glue
    if (list1 != NULL) tail->next = list1;
    else tail->next = list2;

    return dummy.next; 
}

int main() {
    int n, m;
    
    // Read List 1
    scanf("%d", &n);
    struct node* list1 = buildlist(n);
    
    // Read List 2
    scanf("%d", &m);
    struct node* list2 = buildlist(m);
    
    // Merge
    struct node* mergedHead = mergeSortedLists(list1, list2);
    
    // Print result
    struct node* temp = mergedHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}
