#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, -1));
        vector<vector<int>> move{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int row = 0, col = 0;
        int direction = 0;//初始方向向右

        for (int i = 1; i <= n * n; ++i) {
            ret[row][col] = i;
            visited[row][col] = true;

            if (direction == 0 && (col == n-1 || visited[row][col+1]))
                direction = 1;
            else if (direction == 1 && (row == n-1 || visited[row+1][col]))
                direction = 2;
            else if (direction == 2 && (col == 0 || visited[row][col-1]))
                direction = 3;
            else if (direction == 3 && (row == 0 || visited[row-1][col]))
                direction = 0;

            row += move[direction][0];
            col += move[direction][1];
        }

        return ret;
    }
};