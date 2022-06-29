#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canJumpTo = 0; //可以跳到的最远位置
        for (int i = 0; i < n; ++i) {
            if (canJumpTo >= i)
                canJumpTo = max(canJumpTo, i + nums[i]);
        }

        return canJumpTo >= n- 1;
    }
};