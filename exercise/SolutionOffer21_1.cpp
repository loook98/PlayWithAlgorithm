#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int i = 0; //i用来遍历数组
        int k = 0; //[0,k)内为奇数

        for (; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0)
                swap(nums[k++], nums[i]);
        }
        return nums;
    }
};