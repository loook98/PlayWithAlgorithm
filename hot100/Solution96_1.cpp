#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        //计算dp[i]
        for (int i = 2; i <= n; ++i) {
            //每个dp[i]的结果由各个以j为根的树组成
            for (int j = 1; j <= i; ++j) {
                //以j为根的树的个数有dp[j-1]*dp[i-j]
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};