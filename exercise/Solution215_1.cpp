#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = -1;

    int findKthLargest(vector<int> &nums, int k) {
        int index = nums.size() - k; //第k大的元素在升序排序后应该在的位置
        quickSort3Ways(nums, 0, nums.size()-1, index);
        return res;
    }

    //使用3路快排的思路. index为需要找的索引位置
    void quickSort3Ways(vector<int> &nums, int l, int r, int index) {
        if (l >= r) {
            res = nums[l];
            return;
        }

        //partition部分
        swap(nums[l], nums[rand() % (r - l + 1) + l]);

        int lt = l;
        int gt = r + 1;
        int i = l + 1;

        while (i < gt) {
            if (nums[i] < nums[l]) {
                lt++;
                swap(nums[i], nums[lt]);
                i++;
            } else if (nums[i] > nums[l]) {
                gt--;
                swap(nums[i], nums[gt]);
            } else { // ==
                i++;
            }
        }
        swap(nums[l], nums[lt]);
        lt--;

        //快排递归部分
        if (index <= lt)
            quickSort3Ways(nums, l, lt, index);
        else if (index >= gt)
            quickSort3Ways(nums, gt, r, index);
        else { //[lt+1..gt-1]之间
            res = nums[index];
            return;
        }
    }
};