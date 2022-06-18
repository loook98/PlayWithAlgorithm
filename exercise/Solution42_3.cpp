#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int l = 0, r = n - 1;
        //leftMax表示l左侧的最大值，rightMax表示r右侧的最大值
        int leftMax = 0, rightMax = 0;

        int res = 0;
        //计算l处能存多少水要保证它当前的leftMax <= rightMax
        //计算r处能存多少水要保证它当前的rightMax <= leftMax
        while (l <= r){
            if (leftMax <= rightMax){ //计算l处能接多少水
                int curVal = leftMax - height[l];
                if (curVal > 0)
                    res += curVal;

                //更新leftMax
                leftMax = max(height[l], leftMax);
                l++;
            } else { //计算r处能接多少水
                int curVal = rightMax - height[r];
                if (curVal > 0)
                    res += curVal;

                //更新rightMax
                rightMax = max(height[r], rightMax);
                r--;
            }
        }

        return res;
    }
};