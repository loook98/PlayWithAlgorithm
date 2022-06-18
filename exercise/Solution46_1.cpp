#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        visited = vector<bool>(nums.size(), false);
        backtracking(nums, 0, track);
        return res;
    }

    //level是上层调用的层数
    void backtracking(const vector<int>& nums, int level, vector<int>& track){
        if (level == nums.size()){
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]){
                visited[i] = true;
                track.push_back(nums[i]);
                backtracking(nums, level + 1, track);
                track.pop_back();
                visited[i] = false;
            }
        }
    }
};