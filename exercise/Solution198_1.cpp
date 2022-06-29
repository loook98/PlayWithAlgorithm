#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        //dp[i]表示nums[0,i]能偷得的最大现金
        vector<int> dp(n);

        //base case
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        //状态转移
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[n-1];
    }
};