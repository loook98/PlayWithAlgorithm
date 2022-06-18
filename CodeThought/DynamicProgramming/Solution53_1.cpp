#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        //dp[i]表示以nums[i]为结尾的连续子数组的最大和
        vector<int> dp(n);
        //base case
        dp[0] = nums[0];

        int res = dp[0];
        //状态转移
        //以i结尾的连续子数组可以是 「与i-1相连的」 或 「不与i-1相连」
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};