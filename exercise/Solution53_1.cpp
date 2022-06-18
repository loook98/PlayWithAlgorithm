#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n); //dp[i]为以nums中以i结尾的连续子数组的最大和是多少

        //base case
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};