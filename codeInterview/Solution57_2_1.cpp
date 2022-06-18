#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int l = 1, r = 2; //滑动窗口的边界[l...r]
        int sum = 3;//滑动窗口的内容大小
        while (r <= target / 2 + 1) {
            if (sum < target) {
                r++;
                sum += r;
            } else if (sum > target) {
                sum -= l;
                l++;
            } else { // ==
                vector<int> vec;
                for (int i = l; i <= r; ++i) {
                    vec.push_back(i);
                }
                res.push_back(vec);
                r++;
                sum += r;
            }
        }
        return res;
    }
};