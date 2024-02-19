#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> &arr, int val, int low, int high){
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == val)
        return mid;
    else if (arr[mid] <= val)
        return binarySearch(arr, val, mid + 1, high);
    else
        return binarySearch(arr, val, low, mid - 1);
}
int main()
{
    vector<int> arr = { 1, 3, 4, 6 , 9, 10};
    int index = binarySearch(arr, 6, 0, arr.size() - 1);
    cout << index;

    return 0;
}