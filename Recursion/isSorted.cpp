#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr, int i){
    if (i >= arr.size())
        return true;
    if (arr[i - 1] < arr[i])
        return isSorted(arr, i + 1);
    else
        return false;
}
int main()
{
    // "boolalpha" and "noboolalpha" are predefined functions in C++ to read true or false instead as 1 or 0
    // vector<int> arr = { 12, 34, 100, 67, 75};
    vector<int> arr = { 12, 34, 40, 67, 75};
    cout << boolalpha << isSorted(arr, 1);
    return 0;
}