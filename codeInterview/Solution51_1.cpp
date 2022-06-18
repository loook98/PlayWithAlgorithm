#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = 0;

    int reversePairs(vector<int> &nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        if (nums[mid] > nums[mid + 1])
            merge(nums, l, mid, r);
    }

    void merge(vector<int> &nums, int l, int mid, int r) {
        vector<int> aux(r - l + 1);
        for (int i = l; i <= r; ++i) { //这里复制的时候不能直接将整个nums复制给aux，而只需要将nums[l...r]复制给aux
            aux[i-l] = nums[i];
        }

        int i = l, j = mid + 1;
        for (int k = l; k <= r; ++k) {
            if (i <= mid && j <= r) { //左右都没处理完
                if (aux[i - l] <= aux[j - l]) {
                    nums[k] = aux[i - l];
                    i++;
                } else {
                    nums[k] = aux[j - l];
                    j++;
                    res += mid - i + 1;
                }
            } else if (i <= mid) { //左边还没处理完
                nums[k] = aux[i - l];
                i++;
            } else if (j <= r) {  //右边还没处理完
                nums[k] = aux[j - l];
                j++;
            }
        }
    }
};

