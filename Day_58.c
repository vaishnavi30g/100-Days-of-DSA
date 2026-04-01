/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

/**
 * The logic follows the same recursive principle:
 * 1. Preorder[0] is the root.
 * 2. Find root in Inorder to determine left/right subtree sizes.
 * 3. Recurse for Left, then Right, then Print (Postorder).
 */

int pre_idx = 0;

// Function to find the index of a value in the inorder array
int find_index(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

void print_postorder(int preorder[], int inorder[], int in_start, int in_end) {
    if (in_start > in_end) {
        return;
    }

    // Pick current node from preorder using pre_idx and increment it
    int root_val = preorder[pre_idx++];
    
    // Find the index of this node in inorder array
    int pivot = find_index(inorder, in_start, in_end, root_val);

    // Standard Postorder: Left -> Right -> Root
    // Left Subtree
    print_postorder(preorder, inorder, in_start, pivot - 1);
    
    // Right Subtree
    print_postorder(preorder, inorder, pivot + 1, in_end);

    // Print the root (Postorder)
    printf("%d ", root_val);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *preorder = (int *)malloc(n * sizeof(int));
    int *inorder = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    print_postorder(preorder, inorder, 0, n - 1);
    printf("\n");

    free(preorder);
    free(inorder);
    return 0;
}
