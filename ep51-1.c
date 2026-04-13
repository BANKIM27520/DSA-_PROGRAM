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
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}node;
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
node* insert(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
node* findLCA(node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}
int main() {
    int N, n1, n2;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    node* root = NULL;
    printf("Enter the node values: ");
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Enter the two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);
    node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist.\n");
    }
    return 0;
}
