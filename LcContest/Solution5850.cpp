#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[nums.size()-1];
        int max = (a > b ? a : b);
        int min = (a < b ? a : b);
        int res = max%min;
        while (res)
        {
            max = min;//小的给大的
            min = res;//余数给小的
            res = max%min;
        }
        return min;
    }
};