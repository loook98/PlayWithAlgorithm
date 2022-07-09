#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        //dp[i]表示以i结尾的连续子数组的最大和
        vector<int> dp(nums.size());

        //base case
        dp[0] = nums[0];

        int res = nums[0];
        //状态转移
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1]+nums[i] , nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};