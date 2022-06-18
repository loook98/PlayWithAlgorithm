#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        //队首是当前窗口的最大元素.入队新元素时要将队尾小于它的元素全部弹出。
        deque<int> maxDeque;
        int n = nums.size();
        for (int i = 0; i <= k-1; ++i) {
            while (!maxDeque.empty() && maxDeque.back() < nums[i])
                maxDeque.pop_back();
            maxDeque.push_back(nums[i]);
        }

        int l = 0, r = k-1;
        while (r < n){
            res.push_back(maxDeque.front());
            if (nums[l] == maxDeque.front())
                maxDeque.pop_front();
            l++;
            r++;
            if (r == n)
                break;
            while (!maxDeque.empty() && maxDeque.back() < nums[r])
                maxDeque.pop_back();
            maxDeque.push_back(nums[r]);
        }
        return res;
    }
};