#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0) {
                int j;
                for (j = i - 1; j >= 0; --j) {
                    if (nums[j] > i - j)
                        break;
                }
                if (j < 0)
                    return false;
            }
        }
        return true;
    }
};