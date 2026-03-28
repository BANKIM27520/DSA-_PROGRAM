/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'
*/
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
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1; // Intersection found
        }
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }
    return NULL; // No intersection
}
int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* tail1 = NULL;
    struct Node* tail2 = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    
    struct Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }
    
    return 0;
}