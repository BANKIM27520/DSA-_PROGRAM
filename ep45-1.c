/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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
    printf("Height of the tree: %d\n", height(root));
    return 0;
}