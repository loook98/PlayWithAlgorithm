#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        set<int> nums;
        //判断每一行
        for (int i = 0; i < n; ++i) {
            nums.clear();
            for (int j = 0; j < n; ++j) {
                nums.insert(matrix[i][j]);
            }
            if (nums.size() != n)
                return false;
        }

        //判断每一列
        for (int j = 0; j < n; ++j) {
            nums.clear();
            for (int i = 0; i < n; ++i) {
                nums.insert(matrix[i][j]);
            }
            if (nums.size() != n)
                return false;
        }
        return true;
    }
};