#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int preRes = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res[preRes][1]) {
                res[preRes][1] = max(res[preRes][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                preRes++;
            }
        }
        return res;
    }
};