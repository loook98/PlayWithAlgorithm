#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = i + k - 1;
        priority_queue<pair<int, int>> pq;// pq中的每个元素存元素的<值,在数组中的位置>
        for (int l = i; l <= j; ++l) {
            pq.emplace(nums[l], l);
        }
        vector<int> res;
        while (j < nums.size()){
            while (pq.top().second < i)
                pq.pop();
            res.push_back(pq.top().first);

            j++;
            i++;
            if (j < nums.size())
                pq.emplace(nums[j], j);
        }
        return res;
    }
};
