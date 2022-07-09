#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        //先排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) //去重
                continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                //去重
                while (l < r && l > i + 1 && nums[l] == nums[l - 1])
                    l++;
                while (l < r && r < nums.size() - 1 && nums[r] == nums[r + 1])
                    r--;

                if (l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0){
                        res.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (sum < 0){
                        l++;
                    } else{
                        r--;
                    }
                }
            }
        }

        return res;
    }
};