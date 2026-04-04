/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Initialize deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Insert at front
void push_front(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// Insert at rear
void push_back(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// Remove from front
void pop_front(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
}

// Remove from rear
void pop_back(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
}

// Get front element
int front(Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->front->data;
}

// Get rear element
int back(Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    return dq->rear->data;
}

// Check if empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// Get size
int size(Deque* dq) {
    return dq->size;
}

// Clear deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Display deque
void display(Deque* dq) {
    Node* temp = dq->front;
    printf("Deque: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 5);
    push_back(dq, 20);
    display(dq); // Output: 5 10 20

    printf("Front: %d\n", front(dq)); // 5
    printf("Back: %d\n", back(dq));   // 20

    pop_front(dq);
    display(dq); // Output: 10 20

    pop_back(dq);
    display(dq); // Output: 10

    clear(dq);
    display(dq); // Output: (empty)

    return 0;
}
