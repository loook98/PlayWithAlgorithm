#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        //dp[i][0]表示第i天不持有股票时的最大利润
        //dp[i][1]表示第i天持有股票时的最大利润
        vector<vector<int>> dp(n, vector<int>(2));

        //base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        //状态转移
        for (int i = 1; i < n; ++i) {
            //不持有股票 = max(之前就不持有，之前持有今天卖出)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //持有股票 = max(之前就持有，之前不持有今天买入)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};