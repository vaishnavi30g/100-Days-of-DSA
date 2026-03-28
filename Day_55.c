/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>

// Standard Tree Node Structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to print the Right View
void printRightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000]; // Simple array-based queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        // Number of nodes at the current level
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];

            // If this is the last node of the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            // Enqueue left and right children
            if (curr->left != NULL) queue[rear++] = curr->left;
            if (curr->right != NULL) queue[rear++] = curr->right;
        }
    }
}

// Helper function to build the tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        
        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printRightView(root);

    return 0;
}
