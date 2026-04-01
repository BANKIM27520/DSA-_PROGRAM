/*Implement Heap Sort using a Max Heap to sort an array in ascending order. 
First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
#include <stdio.h>
#include <stdlib.h>
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
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void heapSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap[0];
        heap[0] = heap[size - 1];
        size--;
        int j = 0;
        while (2 * j + 1 < size) {
            int largest = j;
            if (heap[2 * j + 1] > heap[largest]) largest = 2 * j + 1;
            if (2 * j + 2 < size && heap[2 * j + 2] > heap[largest]) largest = 2 * j + 2;
            if (largest == j) break;
            swap(&heap[j], &heap[largest]);
            j = largest;
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[MAX];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
