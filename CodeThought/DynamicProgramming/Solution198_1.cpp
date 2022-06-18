#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();

        //dp[i]表示打劫[0,i-1]能得到的最高金额
        vector<int> dp(n + 1);
        //base case
        dp[0] = 0;
        dp[1] = nums[0];

        //状态转移
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};