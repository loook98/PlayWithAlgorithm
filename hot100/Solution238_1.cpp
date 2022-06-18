#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //时间复杂度O(n),空间复杂度O(1) [不算res]
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                res[i] = nums[i];
            else
                res[i] = nums[i] * res[i - 1];
        }
        int rightMultiply = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (i == 0)
                res[i] = rightMultiply;
            else
                res[i] = res[i - 1] * rightMultiply;

            rightMultiply *= nums[i];
        }
        return res;
    }
};