#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;

    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size());
        vector<int> path;
        backTracking(nums, path);

        return res;
    }

    void backTracking(vector<int> &nums, vector<int> &path){
        if (path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                backTracking(nums, path);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};