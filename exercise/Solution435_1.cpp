#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        return n - doNotOverlapIntervals(intervals);
    }

    int doNotOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b) -> bool {return a[1] < b[1];});

        int end = intervals[0][1];
        int count = 1;//至少有一个不相交的区间
        for (auto interval : intervals) {
            int start = interval[0];
            if (start >= end){
                count++;
                end = interval[1];
            }
        }
        return count;
    }
};