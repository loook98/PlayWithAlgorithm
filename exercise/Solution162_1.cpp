#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) { //区间只有一个元素的留到最后处理。这样判断mid > mid + 1时mid+1就不会越界了。
            int mid = l + (r - l) / 2;
            if (isPeak(nums, mid))
                return mid;
            else if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        if (isPeak(nums, l))
            return l;
        return -1;
    }

    inline bool isPeak(vector<int> &nums, int i) {
        if (i == 0)
            return i + 1 < nums.size() ? nums[i] > nums[i + 1] : true;
        if (i == nums.size() - 1)
            return i - 1 >= 0 ? nums[i] > nums[i - 1] : true;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }
};