#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (k == 1 || n == 0)
            return 0;

        int l = 0, r = l + k - 1, min = 100001;
        while (r < n) {
            int tmp = nums[r] - nums[l];
            if (tmp < min)
                min = tmp;
            l++;
            r++;
        }
        return min;
    }
};