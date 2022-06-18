#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int aliveNum = countAlive(i, j, board);
                if ((board[i][j] & 1) == 1){ //活细胞
                    if (aliveNum < 2 || aliveNum >3)
                        board[i][j] |= 2; //标记为死细胞，第二位用来标记
                    else
                        board[i][j] |= 4; //标记为活细胞，第三位用来标记
                } else{ //死细胞
                    if (aliveNum == 3)
                        board[i][j] |= 4; //标记为活细胞，第三位用来标记
                    else
                        board[i][j] |= 2; //标记为死细胞，第二位用来标记
                }
            }
        }

        //再遍历一遍board，按标记将细胞改为相应状态
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((board[i][j] & 2) == 2)//标记为死
                    board[i][j] = 0;
                else if ((board[i][j] & 4) == 4) //标记为活
                    board[i][j] = 1;
            }
        }
    }

    int countAlive(int curX, int curY, const vector<vector<int>> &board){
        int m = board.size();
        int n = board[0].size();
        int neighborIndexes[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

        int ret = 0;
        for (auto neighborIndex : neighborIndexes) {
            int x = curX + neighborIndex[0];
            int y = curY + neighborIndex[1];

            if ( (x >= 0 && x < m) && (y >= 0 && y < n) && (board[x][y] & 1) == 1)
                ret++;
        }
        return ret;
    }
};