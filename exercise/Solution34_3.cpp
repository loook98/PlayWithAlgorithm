#include <bits/stdc++.h>

using namespace std;

//寻找左边界的二分+寻找右边界的二分
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2);

        int tmp0 = findLeft(nums, target);
        int tmp1 = findRight(nums, target);

        res[0] = (tmp0 >= 0 && tmp0 < nums.size() && nums[tmp0] == target) ? tmp0 : -1;
        res[1] = (tmp1 >= 0 && tmp1 < nums.size() && nums[tmp1] == target) ? tmp1 : -1;

        return res;
    }

    int findLeft(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        //二分区间为[l,r)
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                r = mid;
            else if (target < nums[mid])
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    int findRight(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        //二分区间为[l,r)
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                l = mid + 1;
            else if (target < nums[mid])
                r = mid;
            else
                l = mid + 1;
        }

        return l - 1;
    }
};