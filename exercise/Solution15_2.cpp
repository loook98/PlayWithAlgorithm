#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3)
            return res;

        //先排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            //因为已经排序过，故若当前元素>0则后边一定无解
            if (nums[i] > 0)
                break;
            //跳过重复元素
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            //寻找和为0的三个数
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    //缩小范围并去重
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    r--;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                } else if (sum < 0) {
                    l++;
                    //去重
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                } else { //sum > 0
                    r--;
                    //去重
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }

        return res;
    }
};