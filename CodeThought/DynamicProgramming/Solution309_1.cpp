#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        //每一天可能有四种状态
        //0.持有状态 1.不持有（两天前卖出） 2.不持有(今天卖出) 3.不持有(昨天卖出，今天冷冻期)
        vector<vector<int>> dp(n, vector<int>(4));
        //base case
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        //状态转移
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }

        return max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
    }
};