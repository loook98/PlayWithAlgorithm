#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> candidate;
        vector<int> res;
        int l = 0, r = 0;//[l...r)为滑动窗口
        while (r < n){
            while (!candidate.empty() && candidate.back() < nums[r]){
                candidate.pop_back();
            }
            candidate.push_back(nums[r]);
            r++;

            if (r - l == k){
                res.push_back(candidate.front());

                if (candidate.front() == nums[l])
                    candidate.pop_front();
                l++;
            }
        }
        return res;
    }
};