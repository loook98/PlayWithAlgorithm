#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //摩尔投票法
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cond_num = nums[0], count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == cond_num)
                ++count;
            else
                --count;
            if (count == 0){
                cond_num = nums[i];
                count = 1;
            }
        }
        return cond_num;
    }
};