/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7
*/
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
void zigzagLevelOrder(node* root) {
    if (root == NULL) return;
    node* currentLevel[100];
    node* nextLevel[100];
    int currentIndex = 0, nextIndex = 0;
    int leftToRight = 1;
    currentLevel[currentIndex++] = root;
    while (currentIndex > 0) {
        node* temp = currentLevel[--currentIndex];
        printf("%d ", temp->data);
        if (leftToRight) {
            if (temp->left) nextLevel[nextIndex++] = temp->left;
            if (temp->right) nextLevel[nextIndex++] = temp->right;
        } else {
            if (temp->right) nextLevel[nextIndex++] = temp->right;
            if (temp->left) nextLevel[nextIndex++] = temp->left;
        }
        if (currentIndex == 0) {
            leftToRight = !leftToRight;
            for (int i = 0; i < nextIndex; i++) {
                currentLevel[i] = nextLevel[i];
            }
            currentIndex = nextIndex;
            nextIndex = 0;
        }
    }
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
    printf("Zigzag Level Order Traversal: ");
    zigzagLevelOrder(root);
    return 0;
}
