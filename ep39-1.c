/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int heap[MAX];
int size = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int value) {
    if (size == MAX) {
        printf("Heap is full\n");
        return;
    }
    heap[size] = value;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void extractMin() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Extracted Min: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    int i = 0;
    while (2 * i + 1 < size) {
        int smallest = i;
        if (heap[2 * i + 1] < heap[smallest]) smallest = 2 * i + 1;
        if (2 * i + 2 < size && heap[2 * i + 2] < heap[smallest]) smallest = 2 * i + 2;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}
void peek() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Min Element: %d\n", heap[0]);
}
int main() {
    int N, value;
    char operation[20];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(operation, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }
    return 0;
}
