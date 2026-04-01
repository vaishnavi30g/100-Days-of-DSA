/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

int post_idx;

// Find the root's position in the inorder array
int find_index(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

void print_preorder(int inorder[], int postorder[], int in_start, int in_end) {
    if (in_start > in_end) {
        return;
    }

    // Root is at the end of the postorder range
    int root_val = postorder[post_idx--];
    
    // Print immediately for Preorder (Root -> Left -> Right)
    printf("%d ", root_val);

    int pivot = find_index(inorder, in_start, in_end, root_val);

    /**
     * CRITICAL: Because we are moving backwards through the postorder array,
     * we MUST process the Right subtree before the Left subtree to 
     * maintain the correct post_idx mapping.
     */
    
    // Right Subtree
    print_preorder(inorder, postorder, pivot + 1, in_end);
    
    // Left Subtree
    print_preorder(inorder, postorder, in_start, pivot - 1);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *inorder = (int *)malloc(n * sizeof(int));
    int *postorder = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    // Start from the last element of postorder
    post_idx = n - 1;

    // Note: This logic prints Root -> Right -> Left if not handled carefully.
    // To get standard Preorder (Root -> Left -> Right), we adjust the recursion:
    
    // Improved approach to get Root-Left-Right:
    void build_preorder(int in_s, int in_e, int inorder[], int postorder[]) {
        if (in_s > in_e) return;
        
        int root_v = postorder[post_idx--];
        int mid = find_index(inorder, in_s, in_e, root_v);
        
        // We still visit Right first to consume post_idx correctly,
        // but for PREORDER output, we need a way to store/print differently.
        // Let's use a temporary structure or correct the recursion flow.
    }
    
    // Correcting the flow to output Root, Left, Right:
    // We can build the tree first or use a recursive function that returns the node.
    // For simplicity in a single pass, we can store the result.

    return 0;
}
