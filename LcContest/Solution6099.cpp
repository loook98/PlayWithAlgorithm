#include <bits/stdc++.h>

using namespace std;

//6099. 小于等于 K 的最长二进制子序列\
//没做出来
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        //dp[i][j][0]表示s[i,j]的值<=k的最长子序列长度
        //dp[i][j][0]表示s[i,j]的值<=k的最长子序列的值
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));

        //base case
        for (int i = 0; i < n; ++i) {
            dp[i][i][0] = 1;
            dp[i][i][1] = s[i] - '0';
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (((dp[i][j - 1][1] << 1) + (s[j] - '0')) <= k) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = (dp[i][j - 1][1] << 1) + (s[j] - '0');
                } else {
                    dp[i][j][0] = dp[i][j - 1][0];
                    dp[i][j][1] = min((dp[i + 1][j][1] << 1) + (s[j] - '0'),
                                      dp[i][j - 1][1]);
                }
            }
        }

        return dp[0][n-1][0];
    }
};