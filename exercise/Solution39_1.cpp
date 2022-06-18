#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> path;
        backtracking(candidates, 0, path, 0, target);
        return res;
    }

    void backtracking(vector<int> &candidates, int i, vector<int> &path, int pathSum, int target) {
        if (pathSum == target) {
            res.push_back(path);
            return;
        }
        if (pathSum > target) {
            return;
        }

        for (int j = i; j < candidates.size(); ++j) {
            path.push_back(candidates[j]);
            backtracking(candidates, j, path, pathSum + candidates[j], target);
            path.pop_back();
        }
    }
};