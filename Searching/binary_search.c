#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int n, int num)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int m = low + (high - low) / 2;
        if (arr[m] == num)
            return m;
        if (arr[m] < num)
            low = m + 1;
        else
            high = m - 1;
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int num)
{
    if (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == num)
            return m;
        if (arr[m] > num)
            return binarySearch(arr, l, m - 1, num);
        binarySearch(arr, m + 1, r, num);
    }
    return  -1;
}

int main()
{
    int arr[] = {12, 15, 36, 58, 60, 67, 70, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", binary_search(arr, n, 60));
    return 0;
}