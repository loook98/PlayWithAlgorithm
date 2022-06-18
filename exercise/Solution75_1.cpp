#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;
        for (auto num : nums) {
            if (num == 0)
                count0++;
            else if (num == 1)
                count1++;
            else
                count2++;
        }

        int val = 0, index = 0;
        while (index < n){
            if (index == count0)
                val = 1;
            if (index == count0 + count1)
                val = 2;

            nums[index] = val;
            index++;
        }
    }
};*/

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int cnt[3] = {0,0,0};
        for (auto num : nums) {
            cnt[num]++;
        }

        for (int i = 0; i < cnt[0]; ++i) {
            nums[i] = 0;
        }
        for (int i = cnt[0]; i < cnt[0] + cnt[1]; ++i) {
            nums[i] = 1;
        }
        for (int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; ++i) {
            nums[i] = 2;
        }
    }
};