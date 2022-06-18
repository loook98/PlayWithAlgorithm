#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        //第i轮dp[j]表示从coins[0,i]中选择，填满容量为j的背包需要的最少硬币数
        vector<int> dp(amount + 1, INT32_MAX);

        //base case
        dp[0] = 0;

        //状态转移
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] < INT32_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};