#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT32_MAX;
        int windowSum = 0;
        int l = 0, r = 0; //滑动窗口为[l,r)
        while (r < n){
            int num = nums[r];
            r++;
            windowSum += num;

            while (windowSum >= target){
                int len = r - l;
                if (len < res)
                    res = len;

                windowSum -= nums[l];
                l++;
            }
        }

        return res == INT32_MAX ? 0 : res;
    }
};