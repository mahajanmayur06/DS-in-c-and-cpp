#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibnacciNum(int num, unordered_map<int, int> &mp)
{
    if (num <= 1) return num;
    mp[num] = fibnacciNum(num - 1, mp) + fibnacciNum(num - 2, mp);
    return mp[num];
}

int BottomTop (int num){
    unordered_map<int, int> mp;
    mp[0] = 0;
    mp[1] = 1;
    for (int i = 2; i <= num; i++){
        mp[i] = mp[i-1] + mp[i-2];
    }
    return mp[num];
}
int OptimalSpace (int num){
    // prev1 prev2 curr
    int prev1 = 0;
    int prev2 = 1;
    int curr = 0;
    for (int i = 2; i <= num; i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

// 0 1 1 2 3 5 8 13 21 34
int main()
{
    unordered_map<int, int> mp;
    cout << fibnacciNum(8, mp) << endl;
    cout << BottomTop(8) << endl;
    cout << OptimalSpace(8) << endl;


    return 0;
}