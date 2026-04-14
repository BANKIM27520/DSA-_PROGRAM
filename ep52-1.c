/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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
node* findLCA(node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    node* leftLCA = findLCA(root->left, n1, n2);
    node* rightLCA = findLCA(root->right, n1, n2);
    if (leftLCA && rightLCA) {
        return root;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main() {
    int N, n1, n2;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the node values (level-order, -1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    node* root = insertLevelOrder(arr, 0, N);
    printf("Enter the two node values to find LCA: ");
    scanf("%d %d", &n1, &n2);
    node* lca = findLCA(root, n1, n2);
    if (lca) {
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist.\n");
    }
    return 0;
}
