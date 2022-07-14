#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPeek(nums, mid))
                return mid;
            else if (nums[mid] > nums[mid + 1])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1; //不会到这一步
    }

    inline bool isPeek(vector<int> &nums, int i) {
        if (i == 0) {
            if (i + 1 == nums.size() || nums[i] > nums[i + 1])
                return true;
            else
                return false;
        } else if (i == nums.size() - 1) {
            if (i - 1 < 0 || nums[i] > nums[i - 1])
                return true;
            else
                return false;
        } else {
            return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
        }
    }
};