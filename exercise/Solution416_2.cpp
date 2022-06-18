#include <bits/stdc++.h>

using namespace std;

//416. 分割等和子集
//子集背包问题
//把问题转换为： 对于容量为「sum/2」的背包，从「N」个物品中进行选择，是否存在一种装法使的背包刚好装满。每个物品的重量为nums[i]
//进行状态压缩
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

        //dp[i][w]表示对于前i个物品，当前背包容量为w时是否存在一种选择刚好装满背包。
        //状态压缩，i只留一行
        vector<bool> dp(W + 1, false);
        //初始条件dp[0][...]为false(∵没有物品，∴一定不能装满),
        //      dp[...][0]为true(∵背包容量为0，∴一定能装满)
        dp[0] = true;

        //状态转移
        for (int i = 1; i < N + 1; ++i) {
            //状态压缩后w要从右向左计算，目的是防止改变依赖的上次结果
            for (int w = W; w >= 0; --w) {
                if (w < nums[i-1]){//当前背包容量小于物品重量，只能选择不装
                    dp[w] = dp[w];
                } else{ //在装与不装之间选择
                    dp[w] = dp[w-nums[i-1]] ||
                               dp[w];
                }
            }
        }
        return dp[W];
    }
};