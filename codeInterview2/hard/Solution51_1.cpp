#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;

    void merge(vector<int> &nums, int l, int mid, int r) {
        int i = l, j = mid + 1;
        vector<int> aux(r - l + 1);
        int auxIndex = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                aux[auxIndex++] = nums[i++];
            } else {
                aux[auxIndex++] = nums[j++];
                //更新逆序对个数
                count += mid - i + 1;
            }
        }
        while (i <= mid) {
            aux[auxIndex++] = nums[i++];
        }
        while (j <= r) {
            aux[auxIndex++] = nums[j++];
        }

        //更新nums
        for (int k = l; k <= r; ++k) {
            nums[k] = aux[k - l];
        }
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    int reversePairs(vector<int> &nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};