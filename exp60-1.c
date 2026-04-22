/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL) {
        return 1;
    }
    if (index >= totalNodes) {
        return 0;
    }
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}
int isMinHeap(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    if (root->left != NULL && root->data > root->left->data) {
        return 0;
    }
    if (root->right != NULL && root->data > root->right->data) {
        return 0;
    }
    return isMinHeap(root->left) && isMinHeap(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            nodes[i] = createNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }
    struct Node* root = nodes[0];
    int totalNodes = countNodes(root);
    if (isComplete(root, 0, totalNodes) && isMinHeap(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
