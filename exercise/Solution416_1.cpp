#include <bits/stdc++.h>

using namespace std;

//416. 分割等和子集
//子集背包问题
//把问题转换为「sum/2」容量的背包能否装下「N」个物品，每个物品的重量为nums[i]
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int N = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum & 1)//奇数
            return false;
        int W = sum / 2;

        //dp[i][w]表示前i个物品，当前背包容量为w时能否刚好装满背包。
        vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
        //初始条件dp[0][...]为false(∵没有物品，∴一定不能装满),
        //      dp[...][0]为true(∵背包容量为0，∴一定能装满)
        for (int i = 0; i < N + 1; ++i) {
            dp[i][0] = true;
        }

        //状态转移
        for (int i = 1; i < N + 1; ++i) {
            for (int w = 1; w < W + 1; ++w) {
                if (w < nums[i-1]){//当前背包容量小于物品重量，只能选择不装
                    dp[i][w] = dp[i-1][w];
                } else{ //在装与不装之间选择
                    dp[i][w] = dp[i-1][w-nums[i-1]] ||
                               dp[i-1][w];
                }
            }
        }
        return dp[N][W];
    }
};