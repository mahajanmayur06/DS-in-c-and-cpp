#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursive approach
int coinSum1(vector<int> &num, int x){
    if (x == 0){
        return 0;
    }
    if (x < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++){
        int ans = coinSum1(num, x - num[i]);
        if (ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }
    return mini; 
}

int solveRecursively(vector<int> &num, int x){
    int ans = coinSum1(num, x);
    if (ans == INT_MAX){
        return -1;
    }
    return ans;
}

// using memoization
int coinSum2(vector<int> &num, int x, vector<int> &dp){
    if (x == 0){
        return 0;
    }
    if (x < 0){
        return INT_MAX;
    }
    if (dp[x] != -1){
        return dp[x];
    }
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++){
        int ans = coinSum2(num, x - num[i], dp);
        if (ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }
    dp[x] = mini;
    // return mini; 
}

int solveUsingMemoization(vector<int> &num, int x){
    vector<int> dp(x + 1, -1);
    int solve = coinSum2(num, x, dp);
    if (solve == INT_MAX)
        return -1;
    else
        return solve;
}

// solve using tabulation
int solveTab(vector<int> &num, int x){
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++){
        for (int j = 0; j < num.size(); j++){
            if (i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
        }
    }

    if(dp[x] == INT_MAX)
        return -1;
    return dp[x];
}

int main()
{
    vector<int> arr = { 5, 2, 1};
    // cout << solveRecursively(arr, 26);
    // cout << solveUsingMemoization(arr, 26);
    cout << solveTab(arr, 26);
    return 0;
}