#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2);
        res[0] = searchLeftBoundary(nums, target);
        res[1] = searchRightBoundary(nums, target);

        return res;
    }

    //寻找左边界的二分搜素
    int searchLeftBoundary(vector<int> &nums, int target) {
        //区间为[l,r]
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
                r = mid;  //★与找右边界的函数「代码不同，思路相同：都是跳过mid」。
            else if (target < nums[mid])
                r = mid;
            else
                l = mid + 1;
        }

        return (l >= 0 && l < nums.size() && nums[l] == target) ? l : -1;  //★返回l
    }

    //寻找右边界的二分搜素
    int searchRightBoundary(vector<int> &nums, int target) {
        //区间为[l,r)
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (target == nums[mid])
                l = mid + 1; //★与找左边界的函数「代码不同，思路相同：都是跳过mid」。这里如果不跳过，[a,b)时，a==target会死循环。
            else if (target < nums[mid])
                r = mid;
            else
                l = mid + 1;

        }

        return (l - 1 >= 0 && l - 1 < nums.size() && nums[l-1] == target) ? l - 1 : -1; //★返回l-1
    }
};