#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printHeap(int *heap, int *num)
{
    for (int i = 0; i < *num; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void insert(int *heap, int *size, int num)
{
    int index = *size;
    heap[(*size)++] = num;
    while (index > 0)
    {
        int parent = index / 2 - 1;
        if (heap[index] > heap[parent])
        {
            swap((heap + index), (heap + parent));
            index = parent;
        }
        else
            return;
    }
}

void delete(int *heap, int *size)
{
    swap(heap, (heap + *size - 1));
    (*size)--;
    int i = 0;
    while (i < *size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < *size && heap[left] > heap[i])
        {
            swap((heap + left), (heap + i));
            i = left;
        }
        if (right < *size && heap[right] > heap[i])
        {
            swap((heap + left), (heap + i));
            i = right;
        }
        else
            return;
    }
}

int kth_smallest(int *arr, int n, int k)
{
    int size = 0;
    int heap[k];
    for (int i = 0; i < k; i++)
    {
        insert(heap, &size, arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < heap[0])
        {
            delete (heap, &size);
            insert(heap, &size, arr[i]);
        }
    }
    return heap[0];
}
int main()
{
    int arr[] = {23, 45, 77, 34, 87, 74, 92};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d is %dth smallest element\n", kth_smallest(arr, n, 1), 1);
    return 0;
}