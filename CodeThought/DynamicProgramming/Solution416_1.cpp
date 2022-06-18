#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int &num: nums) {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;
        int half = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(half + 1, 0));
        //base case
        for (int j = nums[0]; j <= half; ++j) {
            dp[0][j] = nums[0];
        }

        //状态转移
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= half; ++j) {
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }

        return dp[nums.size()-1][half] == half;
    }
};