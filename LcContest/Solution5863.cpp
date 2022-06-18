#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = 0;

    int countQuadruplets(vector<int> &nums) {
        dfs(nums, 0, 1, 0);
        return res;
    }

    void dfs(vector<int> &nums, int index, int len, int count) { //len,算上当前的长度;count不算当前的大小
        if (len == 5)
            return;

        int n = nums.size();
        for (int i = index; i < n; ++i) {
            if (n - (i + 1) + len < 4)
                break;

            if (len == 4){
                if (nums[i] == count)
                    res++;
                continue;
            }
            dfs(nums, i+1, len +1, count + nums[i]);
        }
    }
};