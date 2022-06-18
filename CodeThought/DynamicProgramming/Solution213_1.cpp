#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int result1 = robNormalArray(nums, 0, nums.size() - 2);
        int result2 = robNormalArray(nums, 1, nums.size() - 1);

        return max(result1, result2);
    }

    int robNormalArray(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];
        vector<int> dp(right - left + 1);
        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);

        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[left + i] + dp[i - 2]);
        }

        return dp[dp.size() - 1];
    }
};