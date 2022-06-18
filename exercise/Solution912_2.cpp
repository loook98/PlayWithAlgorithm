#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        heapify(nums);

        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            shiftDown(nums, 0, i - 1);
        }

        return nums;
    }

    void heapify(vector<int> &nums) {
        int n = nums.size();

        int i = (n - 1 - 1) / 2;
        for (int j = i; j >= 0; --j) {
            shiftDown(nums, j, nums.size() - 1);
        }
    }

    void shiftDown(vector<int> &nums, int i, int end) {
        while (i <= end) {
            int j = i * 2 + 1;
            if (j > end)
                return;

            if (j + 1 <= end && nums[j + 1] > nums[j])
                j++;
            if (nums[j] > nums[i])
                swap(nums[i], nums[j]);
            else
                break;
            i = j;
        }
    }
};