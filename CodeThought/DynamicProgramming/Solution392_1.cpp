#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        //dp[i][j]表示s[0,i-1]和t[0,j-1]的相同子序列长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //base case dp[...][0] = 0, dp[0][...]=0;

        //状态转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1]; //相当于删掉t[j-1]
            }
        }

        return dp[m][n] == m;
    }
};