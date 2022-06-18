#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));

        //base case
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        //状态转移
        for (int i = 1; i < n; ++i) {
            //持有 = max(之前就持有，今天买入)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            //不持有 = max(之前就不持有， 今天卖出)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }

        return dp[n - 1][1];
    }
};