#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<bool> column;  //记录第i列有没有皇后
    vector<bool> dia1; //记录第i个（从上到下）'/'方向的对角线有无皇后。 /方向的同一条对角线上的点x+y相等
    vector<bool> dia2; //记录第i个（从上到下）'\'方向的对角线有无皇后。 \方向的同一条对角线上的点x-y相等

    vector<vector<string>> solveNQueens(int n) {
        column = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);

        string rowStr;
        for (int i = 0; i < n; ++i) {
            rowStr.push_back('.');
        }
        vector<string> board(n, rowStr);
        backtracking(board, 0, n);
        return res;
    }

    void backtracking(vector<string> &board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!column[col] && !dia1[row + col] && !dia2[(row - col) + (n - 1)]) {
                board[row][col] = 'Q';
                column[col] = true;
                dia1[row + col] = true;
                dia2[(row - col) + (n - 1)] = true;

                backtracking(board, row + 1, n);

                board[row][col] = '.';
                column[col] = false;
                dia1[row + col] = false;
                dia2[(row - col) + (n - 1)] = false;
            }
        }
    }
};