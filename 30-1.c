/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff; // Combine like terms
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
void printPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL && current->next->coeff >= 0) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}
int main() {
    int n;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insertTerm(&head, coeff, exp);
    }
    
    printPolynomial(head);
    
    return 0;
}
