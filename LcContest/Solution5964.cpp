#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInArea(int row, int col, int n){
        return (row >= 0 && row < n) && (col >= 0 && col < n);
    }

    void move(char command,int &row, int &col){
        switch (command) {
            case 'U' : row--; break;
            case 'R' : col++; break;
            case 'D' : row++; break;
            default  : col--; break;
        }
    }

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans;

        for (int i = 0; i < m; ++i) {
            //从第i条指令开始
            vector<int> pos(startPos);
            int canExecute = 0;
            for (int j = i; j < m; ++j) {
                move(s[j], pos[0], pos[1]);
                if (!isInArea(pos[0],pos[1], n))
                    break;
                canExecute++;
            }
            ans.emplace_back(canExecute);
        }
        return ans;
    }
};