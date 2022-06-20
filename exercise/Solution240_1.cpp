#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int j = n - 1, i = 0;
        while (j >= 0 && i < m){
            if (matrix[i][j] == target)
                return true;
            else if (target < matrix[i][j])
                j--;
            else
                i++;
        }

        return false;
    }
};