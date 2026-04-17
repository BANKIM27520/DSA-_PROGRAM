/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6*/
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
void rightView(node* root, int level, int* maxLevel) {
    if (root == NULL) return;
    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
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
    int maxLevel = 0;
    printf("Right view of the binary tree: ");
    rightView(root, 1, &maxLevel);
    return 0;
}
