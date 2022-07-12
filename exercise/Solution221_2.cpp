#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0; //返回的是面积，dp数组中是边长。

        //dp[i][j]表示以[i,j]为右下角的最大正方形的边长
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //base case
        // dp[0][...]： matrix为1时为1，为0时为0
        // dp[...][0]： matrix为1时为1，为0时为0
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == '1'){
                dp[i][0] = 1;

                res = 1;
            }

        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == '1'){
                dp[0][j] = 1;

                res = 1;
            }

        }

        //状态转移
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;

                    res = max(res, dp[i][j] * dp[i][j]);
                }
            }
        }

        return res;
    }
};