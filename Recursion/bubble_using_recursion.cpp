#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int i)
{
    if (i >= arr.size())
        return;
    for (int j = i; j <= arr.size(); j++)
    {
        if (arr[j] < arr[i])
            swap(arr[i], arr[j]);
    }
    bubbleSort(arr, i + 1); // recurvsive bubbleSort
}
int main()
{
    vector<int> arr = {56, 78, 90, 12, 3, 4};
    bubbleSort(arr, 0);
    for (int i : arr)
        cout << i << " ";
    return 0;
}