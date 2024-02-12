#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int *heap, int num, int *size)
{
    heap[*size] = num;
    // printf("%d ", *size);

    int index = *size;
    (*size)++;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
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
    // printf("%d ", *size);
    int i = 0;
    while (i < *size)
    {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        if (leftIndex < *size && heap[i] < heap[leftIndex])
        {
            swap((heap + i), (heap + leftIndex));
            i = leftIndex;
        }
        if (rightIndex < *size && heap[i] < heap[rightIndex])
        {
            swap((heap + i), (heap + rightIndex));
            i = rightIndex;
        }
        else
            return;
    }
}

void printHeap(int *heap, int *num)
{
    for (int i = 0; i < *num; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int *heap = (int *)malloc(sizeof(int) * 50);
    int size = 0;
    insert(heap, 23, &size);
    insert(heap, 56, &size);
    insert(heap, 78, &size);
    insert(heap, 14, &size);
    insert(heap, 89, &size);
    insert(heap, 74, &size);
    // insert(heap, 51, &size);
    printf("\n");
    printHeap(heap, &size);
    // delete (heap, &size);
    // printf("\n");
    // printHeap(heap, &size);
    free(heap);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// void insert(int *heap, int num, int *size)
// {
//     (*size)++;
//     heap[*size] = num;
//     printf("%d ", *size);

//     int index = *size;
//     while (index > 1)
//     {
//         int parent = index / 2;
//         if (heap[index] > heap[parent])
//         {
//             swap((heap + index), (heap + parent));
//             index = parent;
//         }
//         else
//             return;
//     }
// }

// void delete(int *heap, int *size)
// {
//     swap((heap + 1), (heap + *size));
//     (*size)--;
//     printf("%d ", *size);
//     int i = 1;
//     while (i < *size)
//     {
//         int leftIndex = 2 * i;
//         int rightIndex = 2 * i + 1;
//         if (leftIndex < *size && heap[i] < heap[leftIndex])
//         {
//             swap((heap + i), (heap + leftIndex));
//             i = leftIndex;
//         }
//         else if (rightIndex < *size && heap[i] < heap[rightIndex])
//         {
//             swap((heap + i), (heap + rightIndex));
//             i = rightIndex;
//         }
//         else
//             return;
//     }
// }

// void printHeap(int *heap, int *num)
// {
//     for (int i = 1; i <= *num; i++)
//     {
//         printf("%d ", heap[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int *heap = (int *)malloc(sizeof(int) * 50);
//     int size = 0;
//     heap[0] = -1;
//     insert(heap, 50, &size);
//     insert(heap, 55, &size);
//     insert(heap, 53, &size);
//     insert(heap, 52, &size);
//     insert(heap, 54, &size);
//     printf("\n");
//     printHeap(heap, &size);
//     delete (heap, &size);
//     printf("\n");
//     printHeap(heap, &size);
//     free(heap);
//     return 0;
// }