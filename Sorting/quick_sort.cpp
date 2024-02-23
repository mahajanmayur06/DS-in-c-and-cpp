#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    int count = 0;
    for (int i  = low + 1; i <= high; i++){
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // place pivot at right position
    int pivotIndex = low + count;
    swap(arr[pivotIndex], arr[low]);

    // left and right part
    i = low, j = high;
    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {67,34,12,90,45,13,89};
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0 ; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}