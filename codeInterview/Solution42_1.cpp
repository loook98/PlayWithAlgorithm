#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int dp[2][n]; //第一行当前元素和前一个元素组成连续子数组；第二行：当前元素不和前边元素组成连续子数组
        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        int ret = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(nums[i] + dp[0][i - 1], nums[i] + dp[1][i - 1]);
            if (dp[0][i] > ret)
                ret = dp[0][i];

            dp[1][i] = nums[i];
            if (dp[1][i] > ret)
                ret = dp[1][i];
        }

        return ret;
    }
};