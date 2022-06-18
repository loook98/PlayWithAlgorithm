#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> move = {{-1, 0},
                                {0,  1},
                                {1,  0},
                                {0,  -1}};
    vector<vector<bool>> visited;
    int m, n;

    bool inArea(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m , vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>> &grid, int curI, int curJ){
        for (int i = 0; i < 4; ++i) {
            int newI = curI + move[i][0];
            int newJ = curJ + move[i][1];

            if (inArea(newI, newJ) && !visited[newI][newJ] && grid[newI][newJ] != '0'){
                visited[newI][newJ] = true;
                dfs(grid, newI, newJ);
            }

        }
    }
};