#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        //dp[i]表示「以i-1结尾」的最长连续有效括号长度
        vector<int> dp(n + 1, 0);

        //base case
        dp[0] = 0;
        dp[1] = 0;

        int res = 0;
        //状态转移
        for (int i = 2; i <= n; ++i) {
            if (s[i - 1] == ')') {
                if (s[i - 1 - 1] == '(')
                    dp[i] = 2 + dp[i - 2];
                else
                    dp[i] = i - dp[i - 1] - 1 - 1 >= 0 && s[i - dp[i - 1] - 1 - 1] == '(' ? (dp[i - 1] + 2 + dp[i-dp[i-1]-1-1]) : 0;

                res = max(res, dp[i]);
            }
        }

        return res;
    }
};