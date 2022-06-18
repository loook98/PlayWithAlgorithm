#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //第k轮的dp[j]表示从coins[0,k]中任意选，装满容量为j的背包有多少种装法
        vector<int> dp(amount + 1, 0);
        //base case
        dp[0] = 1;

        //状态转移
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};