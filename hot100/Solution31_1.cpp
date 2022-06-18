#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //从后向前找找到第一个后边有比它大的元素的位置，然后从中找出比它大的那个最小的元素，交换两个元素。
    //这个元素以后剩余的位置升序排序。
    //若找不到这个元素，则升序排序整个数组即可。
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;

        int i = nums.size() - 1;
        int lMax = nums[i];
        while (i >= 0){
            if (nums[i] < lMax)
                break;
            if (nums[i] > lMax)
                lMax = nums[i];
            i--;
        }

        if (i >= 0){
            int j = i + 1;
            int lMin = INT32_MAX, lMinIndex = -1;
            while (j < nums.size()){
                if (nums[j] > nums[i] && nums[j] < lMin) {
                    lMin = nums[j];
                    lMinIndex = j;
                }
                j++;
            }
            assert(lMinIndex != -1);
            swap(nums[i], nums[lMinIndex]);
            sort(nums.begin() + i + 1, nums.end());
        } else{ //没找到
            sort(nums.begin(), nums.end());
        }
    }
};
