#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (const int &num: nums) {
            sum += num;
        }
        if (abs(target) > sum) // 此时没有方案
            return 0;
        if ((target + sum) % 2 == 1)
            return 0;
        int capacity = (target + sum) / 2;
        //第i轮的dp[j]表示从nums[0,i]中选，装满容量为j的背包的方法数
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;

        //状态转移
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = capacity; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[capacity];
    }
};