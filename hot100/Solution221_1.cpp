#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(); //行数
        int n = matrix[0].size(); //列数
        bool dp[m][n]; //dp[i][j]表示以[i,j]为左上顶点的正方形
        int res = 0;
        //初始化dp
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = true;
                    res = 1;
                } else
                    dp[i][j] = false;
            }
        }

        for (int len = 2; len <= min(m, n); ++len) {
            for (int i = 0; i < m - (len - 1); ++i) {
                for (int j = 0; j < n - (len - 1); ++j) {
                    if (dp[i][j] && dp[i][j + 1] && dp[i + 1][j] && dp[i + 1][j + 1]) {
                        dp[i][j] = true;
                        res = len * len;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }


        return res;
    }
};