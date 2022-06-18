#include <bits/stdc++.h>

using namespace std;

//完全背包问题
//【一维DP数组写法】
int unboundedKnapsack(vector<int> &weight, vector<int> &value, int W) {
    vector<int> dp(W + 1);
    //base case
    dp[0] = 0;

    //状态转移
    for (int i = 0; i < weight.size(); ++i) {
        for (int j = weight[i]; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }

    return dp[W];
}