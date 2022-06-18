#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums2map;
        for (int i = 0; i < nums2.size(); ++i) {
            nums2map.insert({nums2[i], i});
        }
        stack<int> s;
        vector<int> tempRes(nums2.size());
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();

            tempRes[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> res;
        for (int & i : nums1) {
            res.push_back(tempRes[nums2map[i]]);
        }
        return res;
    }
};