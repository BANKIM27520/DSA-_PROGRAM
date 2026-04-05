/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree*/
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
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    int* levelOrder = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &levelOrder[i]);
    }
    struct Node* root = NULL;
    struct Node** queue = (struct Node**)malloc(N * sizeof(struct Node*));
    int front = 0, rear = 0;
    for (int i = 0; i < N; i++) {
        if (levelOrder[i] != -1) {
            struct Node* newNode = createNode(levelOrder[i]);
            if (root == NULL) {
                root = newNode;
            } else {
                if (queue[front]->left == NULL) {
                    queue[front]->left = newNode;
                } else {
                    queue[front]->right = newNode;
                    front++;
                }
            }
            queue[rear++] = newNode;
        } else {
            if (front < rear) {
                front++;
            }
        }
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    free(levelOrder);
    free(queue);
    return 0;
}