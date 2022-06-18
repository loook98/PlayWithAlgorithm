#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                ret.emplace_back(i);
        }

        return ret;
    }
};