#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void merge(vector<int> &nums, int l1, int r1, int l2, int r2) {
        vector<int> aux(r2 - l1 + 1);
        int index1 = l1, index2 = l2, indexAux = 0;

        while (index1 <= r1 && index2 <= r2) {
            if (nums[index1] <= nums[index2]) {
                aux[indexAux++] = nums[index1++];
            } else {
                aux[indexAux++] = nums[index2++];
            }
        }
        while (index1 <= r1)
            aux[indexAux++] = nums[index1++];
        while (index2 <= r2)
            aux[indexAux++] = nums[index2++];

        for (int i = l1; i <= r2; ++i) {
            nums[i] = aux[i - l1];
        }
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        if (nums[mid] > nums[mid + 1])
            merge(nums, l, mid, mid + 1, r);
    }
};