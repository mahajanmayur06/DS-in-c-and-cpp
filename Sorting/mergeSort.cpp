#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int len1 = mid - low + 1;
    int len2 = high - mid;
    int *first = new int[len1];
    int *second  = new int[len2];

    int mainArrayIndex = low;
    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];

    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    // merging two sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = low;
    while (index1 < len1 && index2 < len2){
        if (first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];
    }
    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];
    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];
    
    delete []first; // two delete defined arrays(new learned)
    delete []second;
}

void mergeSort(vector <int> &arr, int low, int high){
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    vector<int> arr = {23,12,67,22,90, 15,10};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}