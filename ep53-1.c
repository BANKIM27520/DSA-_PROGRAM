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
7*/
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
node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n && arr[i] != -1) {
        node* temp = createNode(arr[i]);
        temp->left = insertLevelOrder(arr, 2 * i + 1, n);
        temp->right = insertLevelOrder(arr, 2 * i + 2, n);
        return temp;
    }
    return NULL;
}
void verticalOrder(node* root, int hd, int* minHd, int* maxHd) {
    if (root == NULL) return;
    if (hd < *minHd) *minHd = hd;
    if (hd > *maxHd) *maxHd = hd;
    verticalOrder(root->left, hd - 1, minHd, maxHd);
    printf("%d ", root->data);
    verticalOrder(root->right, hd + 1, minHd, maxHd);
}
int main() {
    int N;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the node values (level-order, -1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    node* root = insertLevelOrder(arr, 0, N);
    int minHd = 0, maxHd = 0;
    verticalOrder(root, 0, &minHd, &maxHd);
    return 0;
}
