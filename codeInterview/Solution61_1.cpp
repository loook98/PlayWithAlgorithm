#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        //统计0出现的次数
        int numOfZero = 0;
        for (int i = 0; i < nums.size() && nums[i] == 0; ++i) {
            numOfZero++;
        }

        //统计缺失的数个数
        int numOfGap = 0;
        int small = numOfZero;
        int big = small + 1;
        while (big < nums.size()) {
            if (nums[small] == nums[big])
                return false;

            numOfGap += nums[big] - nums[small] - 1;
            small++;
            big++;
        }

        return numOfGap <= numOfZero;
    }
};