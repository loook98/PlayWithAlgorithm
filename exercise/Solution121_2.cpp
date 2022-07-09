#include <bits/stdc++.h>

using namespace std;

//买卖股票的最佳时机
//动态规划解法。（此题贪心也可解决）
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //dp[i][0]表示「第i天不持有」股票时的最大利润
        //d[[i][1]表示「第i天持有」股票时的最大利润
        vector<vector<int>> dp(prices.size(), vector<int>(2));

        //base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        //状态转移
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        return dp[prices.size()-1][0];
    }
};