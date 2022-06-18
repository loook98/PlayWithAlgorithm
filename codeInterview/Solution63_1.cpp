#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0|| n == 1)
            return 0;
        int dp = 0;//动态规划的状态 ,dp[i]表示第i日的最大利润，这里这用一个数字就可以表示，不用数组表示每一个
        int minCost = prices[0];
        for (int i = 1; i < n; ++i) {
            dp = max(dp, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }
        return dp;
    }
};