#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort3Ways(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort3Ways(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;

        //partition部分
        swap(nums[l], nums[rand() % (r - l + 1) + l]);

        int lt = l; // [l+1...l]为<
        int i = l+1; // [l+1...i)为=
        int gt = r+1; //[gt...r]为>

        int val = nums[l];
        while (i < gt){
            if (nums[i] < val){
                lt++;
                swap(nums[lt], nums[i]);
                i++;
            } else if (nums[i] > val){
                gt--;
                swap(nums[i], nums[gt]);
            } else{
                i++;
            }
        }
        swap(nums[l], nums[lt]);
        lt--;

        //递归部分
        quickSort3Ways(nums, l , lt);
        quickSort3Ways(nums, gt, r);
    }
};