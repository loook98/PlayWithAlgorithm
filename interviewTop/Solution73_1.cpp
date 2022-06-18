#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> column(n, false);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] && column[j]) //是&&,不应该是||
                    continue;
                if (matrix[i][j] == 0){
                    row[i] = true;
                    column[j] = true;
                }
            }
        }

        //把行改为0
        for (int i = 0; i < m; ++i) {
            if (row[i]){
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        //把列改为0
        for (int j = 0; j < n; ++j) {
            if (column[j]){
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};