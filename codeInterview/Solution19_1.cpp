#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        //初始化首行
        for (int j = 2; j < n; j += 2) {
            if (p[j - 1] == '*' && dp[0][j - 2])
                dp[0][j] = true;
        }
        //状态转移
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true;//*使得p[j-2]出现0次
                    if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true; //*使得p[j-2]重复出现1次
                    if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;
                } else {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;
                    if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};