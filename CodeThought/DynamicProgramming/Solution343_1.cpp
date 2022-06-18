#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);

        //base case
        dp[1] = 1;

        //状态转移
        for (int i = 2; i <= n; ++i) {

            for (int j = 1; j < i; ++j) {
                dp[i] = max({dp[i], j * dp[i - j], j * (i - j)});
            }
        }

        return dp[n];
    }
};