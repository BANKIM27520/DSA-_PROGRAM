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
YES*/
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
int isSymmetric(node* left, node* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;
    if (left->data != right->data) return 0;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
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
    if (isSymmetric(root->left, root->right)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
