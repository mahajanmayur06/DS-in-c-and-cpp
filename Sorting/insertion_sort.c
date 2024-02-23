#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // int arr[] = {45,12,67,23,9,56};
    int arr[] = {23, 45, 67, 13, 56, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    printArray(arr, n);
    return 0;
}