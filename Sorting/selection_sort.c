#include <stdio.h>
#include <stdlib.h>

void swap(int arr[],int m,int n)
{
    int t = arr[m];
    arr[m] = arr[n];
    arr[n] = t;
}

void selection_sort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallest] > arr[j])
                smallest = j;
        }
        swap(arr,i,smallest);
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
    int arr[] = {23,45,67,13,56,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    printArray(arr, n);
    return 0;
}