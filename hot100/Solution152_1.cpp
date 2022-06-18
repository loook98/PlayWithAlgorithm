#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxVec(nums), minVec(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxVec[i] = max(maxVec[i-1] * nums[i], max(minVec[i-1] *nums[i], nums[i]));
            minVec[i] = min(minVec[i-1] * nums[i], min(maxVec[i-1] * nums[i], nums[i]));
        }

        return *max_element(maxVec.begin(), maxVec.end());
    }
};
