#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &v1, vector<int> &v2) { return v1[0] < v2[0]; });

        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0, j = 0;
        int maxRight = intervals[0][1];
        while (j <= n) {
            if (j == n){
                res.push_back({intervals[i][0], maxRight});
                break;
            } else if (intervals[j][0] > maxRight){
                res.push_back({intervals[i][0], maxRight});
                maxRight = intervals[j][1];
                i = j;
            }
            maxRight = max(maxRight, intervals[j][1]);
            j++;
        }

        return res;
    }
};