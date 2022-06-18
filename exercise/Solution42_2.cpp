#include <bits/stdc++.h>

using namespace std;

//双指针接雨水
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int l_max = 0, r_max = 0;
        while (left <= right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if (l_max <= r_max){
                ans += l_max - height[left];
                left++;
            } else{
                ans += r_max - height[right];
                right--;
            }
        }
        return ans;
    }
};