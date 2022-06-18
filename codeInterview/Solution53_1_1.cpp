#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else // ==
                break;
        }

        if (left > right)
            return 0;

        int ret = 0;
        for (int i = mid; i >= 0 && nums[i] == target; --i) {
            ret++;
        }
        for (int i = mid + 1; i < nums.size() && nums[i] == target; ++i) {
            ret++;
        }
        return ret;
    }
};