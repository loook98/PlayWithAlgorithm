#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> original;
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original = nums;
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i],nums[j]);
        }
        return  nums;
    }
};