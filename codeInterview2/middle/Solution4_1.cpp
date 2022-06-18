#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0){
            if (matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};