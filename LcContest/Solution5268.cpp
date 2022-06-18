#include <bits/stdc++.h>

using namespace std;

//5268. 找出两数组的不同
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for (int num : nums1) {
            s1.insert(num);
        }
        for (int num : nums2) {
            s2.insert(num);
        }

        vector<set<int>> _res(2);

        for (int num : nums1) {
            if (!s2.count(num))
                _res[0].insert(num);
        }
        for (int num : nums2) {
            if (!s1.count(num))
                _res[1].insert(num);
        }

        vector<vector<int>> res(2);
        res[0].assign(_res[0].begin(), _res[0].end());
        res[1].assign(_res[1].begin(), _res[1].end());

        return res;
    }
};
