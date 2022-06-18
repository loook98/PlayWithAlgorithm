#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == mid)
                left = mid + 1;
            else if (nums[mid] > mid)
                right = mid - 1;
        }

        if (nums[mid] == mid)
            return nums[mid] + 1;
        if (nums[mid] > mid)
            return nums[mid] - 1;
        return -1; //出错
    }
};