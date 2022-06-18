#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<char>> from(m, vector<char>(n, '-'));

        //base case
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
            from[i][0] = 'u'; //up
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
            from[0][j] = 'l';//left
        }

        //状态转移
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (dp[i - 1][j] < dp[i][j - 1])
                    from[i][j] = 'u';
                else
                    from[i][j] = 'l';
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        //根据from将逆序的路径存入栈中
        int i = m - 1, j = n - 1;
        stack<int> path;
        while (i >= 0 && j >= 0)
        {
            path.push(grid[i][j]);
            if (from[i][j] == 'u')
                i--;
            else
                j--;
        }
        //输出路径
        while (!path.empty()){
            int v = path.top();
            path.pop();
            cout << v << "-";
        }
        cout << endl;
        return dp[m - 1][n - 1];
    }
};