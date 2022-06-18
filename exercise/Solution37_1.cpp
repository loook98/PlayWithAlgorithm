#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool row[9][9];
    bool column[9][9];
    bool grid[3][3][9];

    void solveSudoku(vector<vector<char>> &board) {
        //初始化所有需要的数据结构
        memset(row, false, sizeof(row));
        memset(column, false, sizeof(column));
        memset(grid, false, sizeof(grid));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    row[i][c - '0' - 1] = true;
                    column[j][c - '0' - 1] = true;
                    grid[i/3][j/3][c - '0' - 1] = true;
                }
            }
        }

        //回溯
        backTracing(board, 0, 0);
    }

    bool backTracing(vector<vector<char>> &board, int i, int j) {
        if (j == 9) {
            return backTracing(board, i + 1, 0);
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] != '.') {
            return backTracing(board, i, j + 1);
        }

        for (int k = 0; k < 9; ++k) {
            if (!row[i][k] && !column[j][k] && !grid[i/3][j/3][k]) {
                row[i][k] = true;
                column[j][k] = true;
                grid[i/3][j/3][k] = true;

                board[i][j] = '1' + k;
                if (backTracing(board, i, j + 1))
                    return true;
                board[i][j] = '.';

                row[i][k] = false;
                column[j][k] = false;
                grid[i/3][j/3][k] = false;
            }
        }

        return false;
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(board);
}