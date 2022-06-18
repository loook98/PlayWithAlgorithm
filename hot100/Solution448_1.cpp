#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int index = (nums[i] - 1) % n;
            if (nums[index] <= n)
                nums[index] += n;
        }

        vector<int> res;
        //统计nums中大于n的索引，这些索引就是没有出现的数
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n)
                res.push_back(i+1);
        }
        return res;
    }
};