#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minRow(m, INT32_MAX);
        vector<int> maxCol(n, INT32_MIN);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < minRow[i])
                    minRow[i] = matrix[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] > maxCol[j])
                    maxCol[j] = matrix[i][j];
            }
        }

        //寻找所有幸运数
        vector<int> ret;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                    ret.push_back(matrix[i][j]);
            }
        }
        return ret;
    }
};