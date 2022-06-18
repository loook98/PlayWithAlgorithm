#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //暴力解法，会超时。
    //对于数组中的每个元素，用它min(左边高于它的，右边高于它的) - 它的高度，就是这个元素的位置可以容纳的水量
    int trap(vector<int> &height) {
        int ans = 0;
        int maxLeft, maxRight;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            maxLeft = height[i];
            maxRight = height[i];
            for (int j = i - 1; j >= 0; --j) {
                maxLeft = max(maxLeft, height[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                maxRight = max(maxRight, height[j]);
            }

            ans += min(maxLeft, maxRight) - height[i];
        }
        return ans;
    }
};