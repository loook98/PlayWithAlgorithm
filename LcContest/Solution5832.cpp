#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 1;
        while (i <= n - 2) {
            if ((nums[i - 1] + nums[i + 1]) / 2 == nums[i]) {
                swap(nums[i], nums[i + 1]);
                if (i - 1 >= 1 && (nums[i - 2] + nums[i]) / 2 == nums[i - 1])
                    swap(nums[i - 1], nums[i]);
                i += 2;
            } else {
                i++;
            }
        }

        return nums;
    }
};
