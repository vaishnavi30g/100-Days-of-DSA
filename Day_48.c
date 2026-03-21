/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeaves(struct Node* node) {
    // Base Case: Empty tree or reached a null child
    if (node == NULL) {
        return 0;
    }
    
    // Check if current node is a leaf
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    
    // Recursive sum of leaves in left and right subtrees
    return countLeaves(node->left) + countLeaves(node->right);
}

int main() {
    /* 1
         / \
        2   3
       / \
      4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total Leaf Nodes: %d", countLeaves(root));

    return 0;
}
