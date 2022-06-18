#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;
        deque<int> maxQueue; //队首为窗口最大值
        int l = 0, r = 0;
        while (r < n){
            int numR = nums[r];
            r++;
            while (!maxQueue.empty() && maxQueue.back() < numR){
                maxQueue.pop_back();
            }
            maxQueue.push_back(numR);

            while (r - l == k){
                res.push_back(maxQueue.front());

                int numL = nums[l];
                l++;

                if (numL == maxQueue.front())
                    maxQueue.pop_front();
            }
        }

        return res;
    }
};