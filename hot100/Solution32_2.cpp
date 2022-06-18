#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;

        vector<int> dp(n); //dp[i]为i结尾的最长有效括号长度
        for (int i = 0; i < n; ++i) {
            if (s[i] == '('){
                stk.push(i);
                dp[i] = 0;
            } else{
                if (!stk.empty()){
                    int leftIndex = stk.top();
                    stk.pop();

                    int len = (i - leftIndex + 1) + (leftIndex > 0 ? dp[leftIndex - 1] : 0);
                    dp[i] = len;
                } else{
                    dp[i] = 0;
                }
            }
        }

        //计算最大值
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};