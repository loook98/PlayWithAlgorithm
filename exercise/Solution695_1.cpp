#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    int curSize;
    vector<vector<int>> move{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1){
                    curSize = 0;
                    dfs(grid, i, j);
                    res = max(res, curSize);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &grid, int curI, int curJ){
        if (!inArea(curI, curJ) || grid[curI][curJ] == 0)
            return;

        grid[curI][curJ] = 0; //遍历过的标记为0，就不需要visited数组了
        curSize++;
        for (int i = 0; i < 4; ++i) {
            int nextI = curI + move[i][0];
            int nextJ = curJ + move[i][1];

            dfs(grid, nextI, nextJ);
        }
    }

    inline bool inArea(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
};