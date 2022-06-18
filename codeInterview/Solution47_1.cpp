#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size();//行数
        int n = grid[0].size();//列数

        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) {//初始化第一行
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < m; ++i) {//初始化第一列
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        //计算除第一行第一列以外的dp
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};