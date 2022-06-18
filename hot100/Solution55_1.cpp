#include <bits/stdc++.h>

using namespace std;

//dfs,超时
class Solution {
private:
    bool can = false;
public:
    bool canJump(vector<int> &nums) {
        dfs(nums, 0);
        return can;
    }

    void dfs(vector<int> &nums, int curIndex) {
        if (can)
            return;
        if (curIndex == nums.size() - 1) {
            can = true;
            return;
        }
        for (int i = 1; i <= nums[curIndex]; ++i) {
            dfs(nums, curIndex + i);
        }
    }
};