#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSet = {};
        res.push_back(subSet);
        backTracking(nums, subSet, 0);
        return res;
    }

    void backTracking(vector<int> &nums, vector<int> &subSet, int start){
        for (int i = start; i < nums.size(); ++i) {
            subSet.push_back(nums[i]);
            res.push_back(subSet);
            backTracking(nums, subSet, i + 1);
            subSet.pop_back();
        }
    }
};