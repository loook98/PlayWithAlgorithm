#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //贪心，取中位数就行
    int minOperations(vector<vector<int>> &grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> vec;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int sz = vec.size();
        int target = vec[sz / 2];
        int res = 0;
        for (auto num : vec) {
            if (abs(target - num) % x != 0)
                return -1;
            res += abs(target - num) / x;
        }
        return res;
    }
};