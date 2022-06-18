#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n); //dp[i]表示到第i个台阶需要的最小开销

        //base case
        dp[0] = cost[0];
        dp[1] = cost[1];
        //状态转移
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};