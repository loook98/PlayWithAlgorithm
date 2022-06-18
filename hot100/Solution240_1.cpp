#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowIndex = 0, colIndex = n - 1;
        while (rowIndex <= m-1 && colIndex >= 0){
            if (matrix[rowIndex][colIndex] == target)
                return true;
            if (target < matrix[rowIndex][colIndex])
                colIndex--;
            else
                rowIndex++;
        }
        return false;
    }
};