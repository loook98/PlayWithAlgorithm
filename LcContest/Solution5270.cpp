#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
        //base case
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }

        //状态转移
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //计算dp[i][j]
                for (int k = 0; k < n; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + moveCost[grid[i-1][k]][j]
                                  + grid[i][j]);
                }
            }
        }

        //返回
        int res = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[m-1][j]);
        }
        return res;
    }
};