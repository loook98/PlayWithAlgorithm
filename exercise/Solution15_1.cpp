#include <bits/stdc++.h>

using namespace std;

//三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        return threeSumTarget(nums, 0);
    }

    //寻找两数之和为target的组合. nums传入之前已经排序
    vector<vector<int>> twoSumTarget(vector<int> &nums, int start,int target) {
        vector<vector<int>> res;
        int l = start, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            int lVal = nums[l], rVal = nums[r];

            if (sum < target) {
                while (l < r && nums[l] == lVal)
                    l++;
            } else if (sum > target) {
                while (r > l && nums[r] == rVal)
                    r--;
            } else {
                res.push_back({lVal, rVal});
                while (l < r && nums[l] == lVal)
                    l++;
                while (r > l && nums[r] == rVal)
                    r--;
            }
        }

        return res;
    }

    //寻找三数之和为target组合
    vector<vector<int>> threeSumTarget(vector<int> &nums, int target) {
        vector<vector<int>> res;
        //先排序
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            auto tuples = twoSumTarget(nums, i+1,target - num);
            for (auto tuple : tuples) {
                tuple.push_back(num);
                res.push_back(tuple);
            }

            //跳过重复的第一个元素
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }

        return res;
    }
};