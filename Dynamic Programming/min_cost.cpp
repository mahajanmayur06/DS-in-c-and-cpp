#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoizatioin Top To Bottom
int solve(vector <int> &cost, int n, vector<int>& dp){
    if (n == 0) return cost[0];
    if (n == 1) return cost[1];

    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

int minCostClimbingStair1(vector <int> &cost){
    int n = cost.size();
    vector<int> dp (n + 1, -1);
    return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
}

// by tabulation Bottom To Top
int minCostClimbingStairs2(vector <int> &cost){
    vector<int> temp(cost.size());
    temp[0] = cost[0];
    temp[1] = cost[1];
    int minCost = 0;
    for (int i = 2; i < cost.size(); i++){
        temp[i] = min(temp[i - 1], temp[i - 2]) + cost[i];    
    }
    return min(temp[cost.size() - 1], temp[cost.size() - 2]);
}

// by space optimization
int minCostClimbingStairs3(vector <int> &cost){
    int first = cost[0];
    int second = cost[1];
    int curr = 0;
    for (int i = 2; i < cost.size(); i++){
        curr = cost[i] + min(first, second);
        first = second;
        second = curr;
    }
    return min(first, second);
}

int main()
{
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs2(cost) << " " << minCostClimbingStair1(cost) << " " << minCostClimbingStairs3(cost) ;
    return 0;
}