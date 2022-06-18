#include <bits/stdc++.h>

using namespace std;

//接雨水
//不考虑整体，只考虑局部。位置i处可以接到的水 = min(max[0...i],max[i...n-1]) - i;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_max(n), r_max(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            l_max[i] = (i == 0 ? height[i] : max(height[i], l_max[i-1]));
        }
        for (int i = n-1; i >= 0; --i) {
            r_max[i] = (i == n-1 ? height[i] : max(height[i], r_max[i+1]));
        }

        for (int i = 0; i < n; ++i) {
            ans += min(l_max[i], r_max[i]) - height[i];
        }
        return ans;
    }
};