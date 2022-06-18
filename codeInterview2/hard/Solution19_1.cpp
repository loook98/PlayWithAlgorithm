#include <bits/stdc++.h>

using namespace std;

//正则表达式匹配，动态规划。
class Solution {
public:
    bool match(string &s, string &p, int i, int j) {
        if (i == 0)
            return false;

        if (p[j - 1] == '.')
            return true;
        else
            return s[i - 1] == p[j - 1];
    };

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        //dp[i][j]表示s的「前i个字符构成的子串」是否与p的「前j个字符构成的子串」匹配。
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        //base case, dp[...][0] 为 false  (注：dp[0][...]要算，初始不为false)
        dp[0][0] = true;

        for (int i = 0; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (p[j - 1] != '*') {
                    if (match(s, p, i, j))
                        dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (match(s, p, i, j - 1)) {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2]; //s[i]匹配一次，将s[i]抛弃 || 不匹配
                    } else {
                        dp[i][j] = dp[i][j - 2];  //p[j-1]出现0次
                    }
                }
            }
        }

        return dp[m][n];
    }
};