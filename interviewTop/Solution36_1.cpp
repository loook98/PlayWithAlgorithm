#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> column(9, vector<bool>(10, false));
        vector<vector<bool>> block(9, vector<bool>(10, false));

        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') //忘了空格的地方要处理
                    continue;
                if (row[i][board[i][j]-'0'] || column[j][board[i][j]-'0'] || block[i/3 * 3 + j/3][board[i][j]-'0'])
                    return false;
                else{
                    row[i][board[i][j]-'0'] = true;
                    column[j][board[i][j]-'0'] = true;
                    block[i/3 * 3 + j/3][board[i][j]-'0'] = true;
                }
            }
        }
        return true;
    }
};