#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using recursion
int solveUsingRec(vector<int> &nums, int n){
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    int incl = solveUsingRec(nums, n - 2) + nums[n];
    int excl = solveUsingRec(nums, n - 1);
    return max(incl, excl);
}

// using memoization
int solveUsingMem(vector<int> &nums, vector<int> &dp,int n){
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];
    
    int incl = solveUsingRec(nums, n - 2) + nums[n];
    int excl = solveUsingRec(nums, n - 1);
    dp[n] =  max(incl, excl);
    return dp[n];
}

// using tabulation
int solveUsingTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];

    for (int i = 2; i < n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}
int main()
{
    vector<int> arr = {9 , 9 , 2 , 8};
    vector<int> nums = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    // cout << solveUsingRec(arr, arr.size());
    // vector<int> dp(arr.size() + 1, -1);
    // cout << solveUsingMem(arr, dp, arr.size());
    cout << solveUsingTab(arr) << " " << solveUsingTab(nums);
    return 0;
}