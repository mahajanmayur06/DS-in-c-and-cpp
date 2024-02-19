#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int val, int i)
{
    if (i >= arr.size())
        return false;
    if (arr[i] == val)
        return true;
    else
        return linearSearch(arr, val, i + 1);
}
int main()
{
    vector <int> arr = {1 ,2, 3, 4, 5};
    cout << boolalpha << linearSearch(arr, 3, 0);
    return 0;
}