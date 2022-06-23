#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (l + 1 == r)
                return min(nums[l], nums[r]);
            if (nums[l] < nums[r])
                return nums[l];

            int mid = l + (r - l) / 2;
            if (nums[l] < nums[mid])
                l  = mid;
            else
                r = mid;
        }

        return nums[l];
    }
};