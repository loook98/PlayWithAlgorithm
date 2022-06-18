#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示以i结尾的最长上升子序列的长度
        //注意，dp默认值要为1，否则当前边元素都小于nums[i]时dp[i]就是0了，应该是1
        vector<int> dp(n, 1);
        //base case dp[0] = 1;

        int res = 1; //记录结果
        //状态转移
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};