#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //dp[i][j]表示s[i,j]是不是回文串
        //在计算dp的时候记录res
        vector<vector<int>> dp(n, vector<int>(n, false));

        int res = 0;
        //状态转移
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        res++;
                    } else if (dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        res++;
                    }
                }
                // !=的情况初始化中已经赋值为false了
            }
        }

        return res;
    }
};