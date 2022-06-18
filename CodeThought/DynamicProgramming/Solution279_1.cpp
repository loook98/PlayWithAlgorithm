#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);

        dp[0] = 0;

        for (int j = 0; j <= n; ++j) { //遍历背包
            for (int i = 1; i * i <= j; ++i) { //遍历物品
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};