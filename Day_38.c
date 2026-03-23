/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Deque structure
typedef struct {
    Node *front;
    Node *rear;
    int size;
} Deque;

// Initialize Deque
void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// O(1) Push Front
void push_front(Deque *dq, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

// O(1) Push Back
void push_back(Deque *dq, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = dq->rear;
    newNode->next = NULL;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

// O(1) Pop Front
void pop_front(Deque *dq) {
    if (dq->front == NULL) return;
    Node *temp = dq->front;
    dq->front = dq->front->next;
    
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    
    free(temp);
    dq->size--;
}

// O(n) Reverse
void reverse(Deque *dq) {
    Node *curr = dq->front;
    Node *temp = NULL;
    
    // Swap next and prev for all nodes
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // Move to "next" node (which is now stored in prev)
    }
    
    // Swap front and rear pointers
    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}

void display(Deque *dq) {
    Node *curr = dq->front;
    printf("Deque: ");
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);  // Deque: 5 10 20
    display(&dq);

    reverse(&dq);        // Deque: 20 10 5
    display(&dq);

    pop_front(&dq);      // Deque: 10 5
    display(&dq);

    return 0;
}
