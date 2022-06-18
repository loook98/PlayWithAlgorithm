#include <bits/stdc++.h>

using namespace std;

//先"/"方向沿对角线翻转
//再沿"-"翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //沿对角线翻转
        //每一轮for循环，交换与对角线平行的两组数
        for (int i = 0, j = n - 1; i < m - 1 && j > 0; ++i, --j) {
            int leftX = i, leftY = 0;
            int rightX = m-1, rightY = j;
            //交换元素，然后移到这个平行线的右上一个元素
            while (leftX >= 0 && leftY < n-1){
                swap(matrix[leftX][leftY], matrix[rightX][rightY]);

                leftX--;
                leftY++;

                rightX--;
                rightY++;
            }
        }

        //沿水平线"-" ，上下翻转
        int iHigh = 0, iLow = m - 1;
        while (iHigh < iLow){
            for (int j = 0; j < n; ++j) {
                swap(matrix[iHigh][j], matrix[iLow][j]);
            }

            iHigh++;
            iLow--;
        }
    }
};