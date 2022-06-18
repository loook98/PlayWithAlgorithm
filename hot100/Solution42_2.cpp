#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //对暴力方法中每次都要向左向右遍历整个数组，进行优化。用额外的空间来存储maxLeft和maxRight
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> maxLeft(n, 0), maxRight(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                maxLeft[i] = height[i];
            else
                maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1)
                maxRight[i] = height[i];
            else
                maxRight[i] = max(height[i], maxRight[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return ans;
    }
};