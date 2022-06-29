#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, 0);
        res[0] = leftBound(nums, target);
        res[1] = rightBound(nums, target);

        return res;
    }

    //寻找左边界的二分
    int leftBound(vector<int> &nums, int target) {
        //二分区间为[left,right)
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left >= 0 && left < nums.size() && nums[left] == target)
            return left;
        else
            return -1;
    }

    //寻找右边界的二分
    int rightBound(vector<int> &nums, int target) {
        //区间为[left,right)
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                left = mid + 1; //注意： 这里不+1会死循环。最后返回left-1就能找到了
            } else if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left - 1 >= 0 && left - 1 < nums.size() && nums[left - 1] == target)
            return left - 1;//这里返回left-1就可以找到了。
        else
            return -1;
    }
};