#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0)
            return nums[0];
        if (n == 1 && n % 2 == 1){
            return -1;
        }
        if (n == 1 && n % 2 == 0){
            return nums[0];
        }


        int maxNum = INT32_MIN;
        int i;
        //
        for (i = 0; i < n && i < k - 1; ++i) {
            maxNum = max(maxNum, nums[i]);
        }

        if (i >= n-1)
            return maxNum;
        else if (i == n-2)
            return max(maxNum, max(nums[i], nums[i + 1]));
    }
};