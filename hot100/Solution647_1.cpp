#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //dp[i][j]表示s[i...j]是否为回文串.
        bool dp[n][n];
        int res = 0;
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])){
                    dp[i][j] = true;
                    res ++;
                } else
                    dp[i][j] = false;
            }
        }
        return res;
    }
};