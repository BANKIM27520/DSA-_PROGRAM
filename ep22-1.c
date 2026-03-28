/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int countNodes() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int main() {
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the node values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(value);
    }
    int nodeCount = countNodes();
    printf("Number of nodes in the linked list: %d\n", nodeCount);
    return 0;
}