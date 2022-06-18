#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> set1, set2, set3;
        for (auto num : nums1) {
            set1.insert(num);
        }
        for (auto num : nums2) {
            set2.insert(num);
        }
        for (auto num : nums3) {
            set3.insert(num);
        }

        unordered_set<int> res;
        int count;
        for (auto num : nums1) {
            count = 0;
            if (set1.count(num))
                count++;
            if (set2.count(num))
                count++;
            if (set3.count(num))
                count++;
            if (count >= 2)
                res.insert(num);
        }
        for (auto num : nums2) {
            count = 0;
            if (set1.count(num))
                count++;
            if (set2.count(num))
                count++;
            if (set3.count(num))
                count++;
            if (count >= 2)
                res.insert(num);
        }
        for (auto num : nums3) {
            count = 0;
            if (set1.count(num))
                count++;
            if (set2.count(num))
                count++;
            if (set3.count(num))
                count++;
            if (count >= 2)
                res.insert(num);
        }
        vector<int> ret;
        ret.insert(ret.end(), res.begin(), res.end());
        return ret;
    }
};
