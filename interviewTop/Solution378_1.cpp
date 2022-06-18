#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = findNotBiggerThanMid(matrix, mid, m, n);
            if (count < k){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        return right;
    }

    int findNotBiggerThanMid(const vector<vector<int>> &matrix, int mid, int m, int n) {
        // 以列为单位找，找到每一列最后一个<=mid的数即知道每一列有多少个数<=mid
        int i = m - 1, j = 0;
        int count = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                // 第j列有i+1个元素<=mid
                count += i + 1;
                j++;
            } else {
                // 第j列目前的数大于mid，需要继续在当前列往上找
                i--;
            }
        }
        return count;
    }

};