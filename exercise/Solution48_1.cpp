#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //先沿 / 对角线对称交换， 再沿 —— 线对称交换
    // 对角线时(i, j)对应的位置位((n-1)-j, (n-1)-i)
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        //沿/交换
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                swap(matrix[i][j], matrix[(n - 1) - j][(n - 1) - i]);
            }
        }

        //沿 —— 交换
        int mid = (n - 1) / 2;
        int start = mid;
        if (n % 2 != 0)
            start--;
        for (int i = start; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[(n - 1) - i][j]);
            }
        }
    }
};