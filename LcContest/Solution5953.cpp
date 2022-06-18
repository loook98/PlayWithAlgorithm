#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size();
        for (int l = 0; l <= n-2; ++l) {
            int min = nums[l];
            int max = nums[l];
            for (int len = 2; l + len - 1 < n; ++len) {
                int r = l + len - 1;
                if (nums[r] < min)
                    min = nums[r];
                if (nums[r] > max)
                    max = nums[r];

                ret += max - min;
            }
        }

        return ret;
    }
};