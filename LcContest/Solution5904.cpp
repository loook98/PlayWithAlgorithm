#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> map;

        int n = nums.size();
        int max = -1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int xorRes = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)){
                    xorRes |= nums[i];
                }
            }
            //一种子集
            map[xorRes]++;
            if (xorRes > max)
                max = xorRes;
        }
        return map[max];
    }
};