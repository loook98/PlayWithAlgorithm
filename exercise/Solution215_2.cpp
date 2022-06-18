#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int resultIndex = 0;

    int findKthLargest(vector<int> &nums, int k) {
        resultIndex = nums.size() - k;
        quickSort(nums, 0, nums.size() - 1);
        return nums[resultIndex];
    }

    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;

        int pos = partition(nums, l, r);
        if (pos == resultIndex)
            return;
        else if (resultIndex < pos)
            quickSort(nums, l, pos - 1);
        else
            quickSort(nums, pos + 1, r);
    }

    int partition(vector<int> &nums, int l, int r) {
        int randomIndex = l + rand() % (r - l + 1);
        swap(nums[l], nums[randomIndex]);

        int ltEt = l, i = l + 1;
        while (i <= r) {
            if (nums[i] <= nums[l]) {
                ltEt++;
                swap(nums[ltEt], nums[i]);
                i++;
            } else {
                i++;
            }
        }
        swap(nums[l], nums[ltEt]);
        return ltEt;
    }
};