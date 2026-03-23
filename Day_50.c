/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// 2. Helper function to create a new BST node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 3. Logic to insert a node (to build our test tree)
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// 4. THE SEARCH FUNCTION
// Returns the pointer to the node if found, otherwise NULL
struct Node* search(struct Node* root, int key) {
    // Base Case: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's data
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's data
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 60;
    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in the BST.\n", result->data);
    else
        printf("Element %d not found in the BST.\n", key);

    // Search for a non-existent element
    key = 99;
    if (search(root, key) == NULL)
        printf("Element %d correctly identified as not present.\n", key);

    return 0;
}
