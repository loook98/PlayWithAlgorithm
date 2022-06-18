#include <bits/stdc++.h>

using namespace std;

// 从后向前遍历数组。
// 若有一个元素它后边有大于它的元素，则找出「最小的大于它的元素」，交换这两个元素。然后这个位置后边的元素按升序排列。
// 若数组中不存在这个元素（即整个数组都是有序的）
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return;

        int rightMaxI = n - 1;
        int i = n - 2;
        for (; i >= 0; --i) {
            if (nums[rightMaxI] > nums[i]) {
                //找到最小的交换
                int minValI = rightMaxI;
                for (int j = i + 1; j < n; ++j) {
                    if (nums[j] > nums[i])
                        minValI = nums[minValI] < nums[j] ? minValI : j;
                }
                swap(nums[i], nums[minValI]);
                //将后边的元素升序排列
                sort(nums.begin() + i + 1, nums.end());

                break;
            }
            rightMaxI = i;
        }

        //若数组中不存在这个元素（整个数组是降序的）,则翻转为升序即可
        if (i == -1){
            int l = 0, r = n - 1;
            while (l < r){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
    }
};