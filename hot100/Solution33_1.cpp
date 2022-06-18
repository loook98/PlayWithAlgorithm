#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;

            if (l == r){
                if (nums[l] == target) {
                    return l;
                } else {
                    return -1;
                }
            }

            if (nums[l] <= nums[mid]) { //左边有序
                if (target >= nums[l] && target <= nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            } else if (nums[mid + 1] <= nums[r]) { //右边有序
                if (target >= nums[mid + 1] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return -1;
    }
};
