#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();

        //dp[i]表示以i结尾的最长连续递增子序列长度
        vector<int> dp(n, 1);
        //base case dp[0] = 1

        int res = 1;
        //状态转移
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }

        return res;
    }
};