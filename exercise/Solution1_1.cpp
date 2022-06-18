#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> targetRemain;
        targetRemain.insert({nums[0], 0});

        for (int i = 1; i < nums.size(); ++i) {
            if (targetRemain.count(target - nums[i]))
                return {targetRemain[target-nums[i]], i};
            targetRemain[nums[i]] = i;
        }
        return {};
    }
};