#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //dp[i][0]表示第i天不持有股票的最大利润，dp[i][1]表示第i天持有股票的最大利润。
        vector<vector<int>> dp(n, vector<int>(2));
        //base case
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            //今天不持有的最大利润= max(昨天就不持有, 昨天持有今天卖出)
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            //今天持有的最大利润= max(今天才买入， 昨天就持有)
            dp[i][1] = max(-prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
    }
};