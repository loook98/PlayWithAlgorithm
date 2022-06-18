#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool { return a[1] < b[1];});

        int end = points[0][1];
        int count = 1;

        for (auto point : points) {
            int start = point[0];
            if (start > end){
                count++;
                end = point[1];
            }
        }
        return count;
    }
};