#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> smallHeap;
        priority_queue<int> bigHeap;

        for (auto num : nums) {
            bigHeap.emplace(num);
            smallHeap.emplace(num);
        }

        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] > smallHeap.top() && nums[right] < bigHeap.top())
                break;

            if (nums[left] <= smallHeap.top()) {
                smallHeap.pop();
                left++;
            }

            if (nums[right] >= bigHeap.top()) {
                bigHeap.pop();
                right--;
            }
        }

        if (left < right)
            return right - left + 1;
        else
            return 0;
    }
};