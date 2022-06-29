#include <bits/stdc++.h>

using namespace std;

//1. 数组前n-1个元素调用一次「打家劫舍I」得出一个值
//2. 数组后n-1个元素调用一次「打家劫舍I」得出一个值
//两次「打家劫舍I」得到的最大值返回即可。
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int val1 = robVersion1(nums, 0, nums.size() - 2);
        int val2 = robVersion1(nums, 1, nums.size() - 1);

        return max(val1, val2);
    }

    int robVersion1(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];

        vector<int> dp(end - start + 1);

        //base case
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        //状态转移
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }

        return dp[dp.size() - 1];
    }
};