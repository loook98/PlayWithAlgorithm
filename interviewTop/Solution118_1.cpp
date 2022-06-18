#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            int sz = i + 1;
            res[i] = vector<int>(sz);
            res[i][0] = 1;
            res[i][sz - 1] = 1;
            for (int j = 1; j < sz - 1; ++j)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }

        return res;
    }
};