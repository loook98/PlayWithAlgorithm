#include <bits/stdc++.h>

using namespace std;

//518. 零钱兑换 II
//完全背包问题
//此问题可以转换为 容量为amount的背包，有N个物品，每个物品个数不限，各个物品的重量为coins[i]。问：有多少种装法可以装满背包

//状态： 当前可选择的物品、当前背包容量
//选择： 装不装当前物品

//dp数组 : dp[i][w]表示在前i个物品可以选择的情况下，有几种方法可以装满背包
//base case:  dp[0][...] = 0;  dp[...][0] = 1;
//状态转移: dp[i][w] = 不装当前物品 + 装当前物品 = dp[i-1][w]+dp[i][w-coins[i-1]]  (注：i-1是因为coins索引从0开始)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N+1, vector<int>(amount+1, 0));

        //base case
        for (int i = 0; i < N+1; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < N+1; ++i) {
            for (int w = 1; w < amount + 1; ++w) {
                if (w < coins[i-1]){ //只能不装
                    dp[i][w] = dp[i-1][w];
                } else{ //不装+装的方法数
                    dp[i][w] = dp[i-1][w] + dp[i][w-coins[i-1]];
                }
            }
        }

        return dp[N][amount];
    }
};