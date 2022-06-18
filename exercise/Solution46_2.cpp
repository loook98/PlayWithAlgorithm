#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;

    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        vector<int> path;
        backTracing(nums, 0, path);
        return res;
    }

    void backTracing(vector<int> &nums, int level, vector<int> &path){
        if (level == nums.size()){
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                backTracing(nums, level + 1, path);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};