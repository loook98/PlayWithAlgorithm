#include <bits/stdc++.h>

using namespace std;

//暴力解法
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int max = nums[i], min = nums[i];
            for (int j = i; j < n; ++j) {
                if (nums[j] > max)
                    max = nums[j];
                if (nums[j] < min)
                    min = nums[j];
                res += max - min;
            }
        }
        return res;
    }
};