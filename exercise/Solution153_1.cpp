#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        if (nums.size() == 1)
            return nums[0];
        //二分，每次选择包含最小元素的区间
        while (l < r) {
            if (l + 1 == r)
                return min(nums[l],nums[r]);

            int mid = l + (r - l) / 2;
            //如果整个区间有序则返回左侧元素即可
            if (nums[l] < nums[r]) {
                return nums[l];
            } else if (nums[mid] < nums[r]){
                r = mid;
            } else{
                l = mid;
            }
        }

        return -5001; //出错
    }
};