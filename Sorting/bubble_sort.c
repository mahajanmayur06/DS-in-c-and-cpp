#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int m, int n)
{
    int t = arr[m];
    arr[m] = arr[n];
    arr[n] = t;
}

// here for round 1 first largest element will be placed for right postion
// here for round i ith largest element will be placed for right postion

void BubbleSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int swaped = 0;
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                swaped = 1;
            }
        }
        if (!swaped)
            break; // for best case scenario,  where array is already sorted.. 
            // Best Case: O(n) and worst case: O(n^2);
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
    BubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}