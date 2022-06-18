#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0 || n == 1)
            return s;
        bool dp[n][n];//dp[i][j]表示s[i..j]子串是不是回文串
        //初始化长度为1的子串的dp
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        string res = s.substr(0, 1);
        //计算长度为2--n的子串的dp
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = s[i] == s[j];
                if (l != 2)
                    dp[i][j] = dp[i][j] && dp[i + 1][j - 1];
                if (dp[i][j] && l > res.size())
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};