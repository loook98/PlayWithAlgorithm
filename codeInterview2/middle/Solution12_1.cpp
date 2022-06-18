#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    bool canFind = false;
    vector<vector<int>> directions = {{-1, 0},
                                      {0,  1},
                                      {1,  0},
                                      {0,  -1}};

    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                find(board, word, i, j, 0);
                if (canFind)
                    return true;
            }
        }
        return false;
    }

    void find(vector<vector<char>> &board, const string &word, int i, int j, int curLen) {
        if (canFind == true)
            return;

        if (curLen >= word.size() || board[i][j] != word[curLen])
            return;

        if (curLen == word.size() - 1 && board[i][j] == word[curLen]) {
            canFind = true;
            return;
        }

        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            if (inArea(newI, newJ) && !visited[newI][newJ])
                find(board, word, newI, newJ, curLen + 1);
        }
        visited[i][j] = false;
    }

    bool inArea(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
};