#include <bits/stdc++.h>

using namespace std;

//O(n^2)动态规划解法
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        //d[i]表示以nums[i]结尾的最长递增子序列长度
        vector<int> dp(n, 1);

        //base case dp[0] = 1;

        int res = 1;
        //状态转移
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};