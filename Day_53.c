/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

// Standard Node Structure
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the range of Horizontal Distances
void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Level Order Traversal to print nodes at a specific HD
void printVerticalLine(struct Node* root, int line_no, int hd) {
    if (root == NULL) return;

    // We use a queue-based approach here to ensure top-to-bottom order
    struct Node* queue[1000];
    int hd_queue[1000];
    int head = 0, tail = 0;

    queue[tail] = root;
    hd_queue[tail++] = hd;

    while (head < tail) {
        struct Node* temp = queue[head];
        int curr_hd = hd_queue[head++];

        if (curr_hd == line_no) {
            printf("%d ", temp->data);
        }

        if (temp->left) {
            queue[tail] = temp->left;
            hd_queue[tail++] = curr_hd - 1;
        }
        if (temp->right) {
            queue[tail] = temp->right;
            hd_queue[tail++] = curr_hd + 1;
        }
    }
}

// Function to build tree from level-order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (head < tail && i < n) {
        struct Node* curr = queue[head++];
        
        // Left
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;
        
        // Right
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[tail++] = curr->right;
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

    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int i = min; i <= max; i++) {
        printVerticalLine(root, i, 0);
        printf("\n");
    }

    return 0;
}
