#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 1; i < n-1; ) {
            int l = i - 1, r = i + 1;
            while (l-1 >= 0 && nums[l] == nums[i])
                l--;
            while (r+1 < n && nums[r] == nums[i])
                r++;

            if ((nums[i] > nums[l] && nums[i] > nums[r]) ||
                    (nums[i] < nums[l] && nums[i] < nums[r]))
                res++;

            i = r;
        }
        return res;
    }
};