/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->front > q->rear;
}
void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->data[++q->rear] = value;
    }
}
int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1; // Queue is empty
}
typedef struct {
    int data[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isStackEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    }
}
int pop(Stack* s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    }
    return -1; // Stack is empty
}

void reverseQueue(Queue* q) {
    Stack s;
    initStack(&s);
    while (!isEmpty(q)) {
        push(&s, dequeue(q));
    }
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}
void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int N, value;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    printf("Enter elements:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }
    reverseQueue(&q);
    printf("Reversed queue:\n");
    printQueue(&q);
    return 0;
}
