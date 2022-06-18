#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        //dp[i]表示i个数可组成的二叉搜索树的个数
        vector<int> dp(n + 1, 0);

        //初始化
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            //dp[i]的值为各个「以j∈[1,i]为根节点的二分搜索树的数量」之和
            //而「以j为根节点的二分搜索树的数量」为dp[i-1] * dp[j-i]
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};