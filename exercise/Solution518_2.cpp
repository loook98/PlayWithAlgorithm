#include <bits/stdc++.h>

using namespace std;

//完全背包问题进行状态压缩
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < N+1; ++i) {
            //注意：因为这里不压缩之前是dp[i][w-coins[i-1]]，是dp[i]...,不是dp[i-1]....,就必须用到新值。
            //所以w必须从左向右算，而不是向之前（01背包、子集背包）一样从右向左算。
            for (int w = 1; w < amount+1; ++w) {
                //w < coins[i-1]的情况下，只能不装，dp[w] = dp[w]，可以省略掉
                if (w >= coins[i-1])
                    dp[w] = dp[w] + dp[w - coins[i-1]];
            }
        }
        return dp[amount];
    }
};