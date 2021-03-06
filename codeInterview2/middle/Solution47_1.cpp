#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        //base case
        for (int i = 0; i < m; ++i) {
            dp[i][0] = grid[i][0] + (i > 0 ? dp[i-1][0] : 0);
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j] + (j > 0 ? dp[0][j-1] : 0);
        }

        //
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};