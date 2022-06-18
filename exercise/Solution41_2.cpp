#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long hashVal = (long long)nums[i] - 1;
            while (hashVal != i && (hashVal >= 0 && hashVal < n) && nums[hashVal] != nums[i]) {
                swap(nums[i], nums[hashVal]);
                hashVal = (long long)nums[i] - 1;
            }
        }

        //找到nums[i] ≠ i + 1的，则i+1就是第一个未出现的
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        //数组中没找到，则第一个未出现的是n+1
        return n + 1;
    }
};