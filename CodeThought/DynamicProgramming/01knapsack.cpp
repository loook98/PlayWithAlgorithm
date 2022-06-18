#include <bits/stdc++.h>

using namespace std;

int knapsack(int N, int W, vector<int> &weight, vector<int> &value) {
    //dp[i][j]表示从「0~i物品」中选，放入「容量为j的背包」中，「最多的价值」是多少。
    vector<vector<int>> dp(N, vector<int>(W + 1));
    //base case
    for (int i = 0; i < N; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= W; ++j) {
        dp[0][j] = j >= weight[0] ? value[0] : 0;
    }

    //状态转移
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    return dp[N - 1][W];
}