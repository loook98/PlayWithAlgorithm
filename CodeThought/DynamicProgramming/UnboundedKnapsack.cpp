#include <bits/stdc++.h>

using namespace std;

//完全背包问题：
//从N个物品中任意挑选（每个物品的数量无限），放入容量为W的背包中，可以放入的最大物品价值
//【二维dp数组写法】
int unboundedKnapsack(vector<int> &weight, vector<int> &value, int W) {
    int N = weight.size();
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));

    //base case
    for (int j = weight[0]; j <= W; ++j) {
        dp[0][j] = (j / weight[0]) * value[0];
    }

    //状态转移
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j < weight[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + value[i]);
        }
    }

    return dp[N-1][W];
}