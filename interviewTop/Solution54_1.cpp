#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);

        vector<vector<int>> steps = {{-1, 0},
                                     {0,  1},
                                     {1,  0},
                                     {0,  -1}}; //上、右、下、左
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int direction = 1;
        int row = 0, column = 0;
        for (int i = 0; i < m * n; ++i) {
            visited[row][column] = true;
            res[i] = matrix[row][column];

            if (direction == 1 && (column == n - 1 || visited[row][column + 1]))
                direction = 2;
            else if (direction == 2 && (row == m - 1 || visited[row + 1][column]))
                direction = 3;
            else if (direction == 3 && (column == 0 || visited[row][column - 1]))
                direction = 0;
            else if (direction == 0 && (row == 0 || visited[row - 1][column]))
                direction = 1;

            row += steps[direction][0];
            column += steps[direction][1];
        }
        return res;
    }
};