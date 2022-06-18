#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        //dp[i][j]表示s[i,j]中最长的回文子序列
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 0)
                        dp[i][j] = 1;
                    else if (j - i == 1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};