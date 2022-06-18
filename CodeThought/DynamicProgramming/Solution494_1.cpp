#include <bits/stdc++.h>

using namespace std;

//这个二位dp解法输入为
// [0,0,0,0,0,0,0,0,1]
// 1
// 时算的结果不对，用1维滚动DP写吧
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (const int &num: nums) {
            sum += num;
        }
        if ((target + sum) % 2 == 1)
            return 0;
        int capacity = (target + sum) / 2;
        //dp[i][j]表示从nums[0,i]中选，装满容量为j的背包的方法数
        vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0));

        //base case
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][0] = 1;
        }
        if (nums[0] <= capacity)
            dp[0][nums[0]] = 1;

        //状态转移
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= capacity; ++j) {
                if (j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
        }

        //test
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j <= capacity; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        //

        return dp[nums.size() - 1][capacity];
    }
};