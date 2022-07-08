#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();

        //dp[i][0]表示以i结尾的连续数组的「最小「负数」乘积」
        //dp[i][1]表示以i结尾的连续数组的「最大「正数」乘积」
        vector<vector<int>> dp(n, vector<int>(2));

        //base case
        if (nums[0] == 0) {
            dp[0][0] = 0;
            dp[0][1] = 0;
        } else if (nums[0] < 0) {
            dp[0][0] = nums[0];
            dp[0][1] = 0;
        } else {
            dp[0][0] = 0;
            dp[0][1] = nums[0];
        }

        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                dp[i][0] = dp[i][1] = 0;
            } else if (nums[i] < 0) {
                dp[i][0] = min(nums[i], dp[i - 1][1] * nums[i]);
                dp[i][1] = dp[i - 1][0] * nums[i];
            } else { // > 0
                dp[i][0] = dp[i - 1][0] * nums[i];
                dp[i][1] = max(nums[i], dp[i - 1][1] * nums[i]);
            }

            res = max({res, dp[i][0], dp[i][1]});
        }

        return res;
    }
};