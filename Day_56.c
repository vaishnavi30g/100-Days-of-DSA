/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check if two subtrees are mirrors
bool isMirror(struct Node* t1, struct Node* t2) {
    // If both are NULL, they are mirrors
    if (t1 == NULL && t2 == NULL) return true;
    
    // If only one is NULL, or values differ, they aren't mirrors
    if (t1 == NULL || t2 == NULL) return false;
    if (t1->data != t2->data) return false;

    // Check outer children and inner children recursively
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct Node* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

// Level-order tree builder
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;
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
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    
    if (isSymmetric(root)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
