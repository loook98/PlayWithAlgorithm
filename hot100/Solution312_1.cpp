#include <bits/stdc++.h>

using namespace std;

//戳气球
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //添加两侧的虚拟气球
        vector<int> points(n+2, 1);
        for (int i = 1; i <= n; ++i) {
            points[i] = nums[i-1];
        }
        //dp[i][j]表示(i...j)范围内的气球被戳破获得的最大硬币数，气球范围为[1....n];
        //base case为 0 <= i <= n+1,j <= k+1, dp[i][j] = 0;
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int i = n-1; i >= 0; --i) {
            for (int j = i+2; j <= n+1; ++j) {
                for (int k = i+1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] + points[i]*points[k]*points[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};