#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //向右、下、左、上移动时坐标的增量
    vector<vector<int>> move = {{0,  1},
                                {1,  0},
                                {0,  -1},
                                {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        //初始位置为[0,0], 总共需要走steps步,当前位第i步，
        int i = 1;
        int steps = m * n;
        int curI = 0, curJ = 0;
        int direction = 0; //初始方向为向右
        while (i <= steps) {
            res.push_back(matrix[curI][curJ]);
            //不使用visited数组，直接改为不可能出现的值，标记已访问过的节点，减少空间复杂度。
            matrix[curI][curJ] = INT32_MIN;
            //判断是否需要切换方向
            if (direction == 0 &&
                (curJ == n - 1 || matrix[curI][curJ + 1] == INT32_MIN))
                direction = 1;
            else if (direction == 1 &&
                     (curI == m - 1 || matrix[curI + 1][curJ] == INT32_MIN))
                direction = 2;
            else if (direction == 2 &&
                     (curJ == 0 || matrix[curI][curJ - 1] == INT32_MIN))
                direction = 3;
            else if (direction == 3 &&
                     (curI == 0 || matrix[curI - 1][curJ] == INT32_MIN))
                direction = 0;

            //更新curI， curJ
            curI += move[direction][0];
            curJ += move[direction][1];
            //走了一步
            i++;
        }
        return res;
    }
};