/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void createCircularLinkedList(struct Node** head, int n) {
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (*head == NULL) {
            *head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (tail != NULL) {
        tail->next = *head; // Make it circular
    }
}
void traverseCircularLinkedList(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
}
int main() {
    int n;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    createCircularLinkedList(&head, n);
    traverseCircularLinkedList(head);
    
    return 0;
}
