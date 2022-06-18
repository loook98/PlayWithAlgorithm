#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int overlapStart = -1, overlapNum = 0;
        int n = intervals.size();

        for (int i = 0; i < n; ++i) {
            //记录与newInterval重叠的区间
            if (!(newInterval[1] < intervals[i][0] || newInterval[0] > intervals[i][1])) {
                if (overlapNum == 0) {
                    overlapStart = i;
                }
                overlapNum++;
            }
        }

        vector<vector<int>> res;
        //如果有重叠，将「重叠的区间（可能有多个）」和「新区间」合并为一个区间
        if (0 != overlapNum) {
            for (int i = 0; i < overlapStart; ++i) {
                res.push_back(intervals[i]);
            }

            //合并区间
            for (int i = overlapStart; i < overlapStart + overlapNum; ++i) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            //加入res
            res.push_back(newInterval);

            for (int i = overlapStart + overlapNum; i < n; ++i) {
                res.push_back(intervals[i]);
            }
        } else {//新区间与原区间没有重叠，将新区间插入合适的位置即可
            for (int i = 0; i < n; i++) {
                if ( (i > 0 ? newInterval[0] > intervals[i-1][1] : true) && newInterval[1] < intervals[i][0])
                    res.push_back(newInterval);
                res.push_back(intervals[i]);
            }
            if (intervals.size() == 0 || newInterval[0] > intervals[n - 1][1])
                res.push_back(newInterval);
        }

        return res;
    }
};