#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int *heap, int size, int index)
{
    int largest = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    if (leftIndex < size && heap[largest] < heap[leftIndex])
        largest = leftIndex;
    if (rightIndex < size && heap[largest] < heap[rightIndex])
        largest = rightIndex;

    if (largest != index)
    {
        swap((heap + largest), (heap + index));
        heapify(heap, size, largest);
    }
}

void buildHeap(int *heap, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

int main()
{
    int n;
    printf("Enter value of n ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    buildHeap(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}