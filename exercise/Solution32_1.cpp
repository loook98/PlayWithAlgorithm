#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        int res = 0;
        // dp[i]表示以i结尾的最长连续有效括号长度。
        // 注意：必须是以i结尾的，连续的，有效的。
        vector<int> dp(n);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '('){
                dp[i] = 0;
            } else{
                if (s[i-1] == '('){
                    dp[i] = (i - 2 >= 0 ? dp[i-2] : 0) + 2;
                } else{
                    int start = i - dp[i-1] -1;
                    if (start >= 0){
                        if (s[start] == '(')
                            dp[i] = dp[i-1] + 2 + (start - 1 >= 0 ? dp[start - 1] : 0);
                        else
                            dp[i] = 0;
                    } else{
                        dp[i] = 0;
                    }
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};