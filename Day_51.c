/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/

#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// LCA Logic
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both nodes are smaller, LCA is on the left
        if (p < root->data && q < root->data)
            root = root->left;
        // If both nodes are larger, LCA is on the right
        else if (p > root->data && q > root->data)
            root = root->right;
        // We found the split point
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input processing
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &p, &q);

    // Find and print LCA
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->data);
    }

    return 0;
}
