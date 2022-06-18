#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //动态规划,dp[i]表示以i为结尾的连续子数组的最大和，dp[i] = max(dp[i-1] + nums[i], nums[i])
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int pre = 0, maxNum = nums[0];
        for (auto num : nums) {
            pre = max(pre + num, num);
            maxNum = max(maxNum, pre);
        }
        return maxNum;
    }
};