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
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(heap, size, i);
}

void heapSort(int heap[], int n)
{
    int size = n - 1;
    while (size >= 0)
    {
        swap(heap, (heap + size));
        heapify(heap, size, 0);
        size--;
    }
}

int main()
{
    int n;
    printf("Enter value of n ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // int arr[] = { 145,63,85,205,96,14,10,9,25,64,79,82,36,40,180,56,23,84,27,50};
    buildHeap(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

/*
After building heap
205 145 180 84 96 82 85 56 63 64 79 14 36 40 10 9 23 25 27 50
Sorted array is
9 10 14 23 25 27 36 40 50 56 63 64 79 82 84 85 96 145 180 205
*/