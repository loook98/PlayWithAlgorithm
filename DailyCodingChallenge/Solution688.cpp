#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    bool inArea(int i, int j, int n){
        return (i >= 0 && i < n) && (j >= 0 && j < n);
    }
    double knightProbability(int n, int k, int row, int column) {
        //dp[k][i][j]表示在[i,j]位置走k步仍在棋盘上的概率
        vector<vector<vector<double>>> dp(k + 1,vector<vector<double>>(n, vector<double>(n, 0.0)));
        //初始条件,dp[0][i][j]均为1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[0][i][j] = 1.0;
            }
        }

        for (int loopK = 1; loopK < k + 1; ++loopK) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    //当前位置的8个方向
                    for (int d = 0; d < 8; ++d) {
                        int nextI = i + directions[d][0];
                        int nextJ = j + directions[d][1];
                        if (inArea(nextI,nextJ, n))
                            dp[loopK][i][j] += (1.0/8.0) * (dp[loopK-1][nextI][nextJ]);
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};