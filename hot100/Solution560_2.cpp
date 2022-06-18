#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        //要用到《两数之和》的思路，即在遍历前缀和的每个元素i时记录前边出现i-k的个数
        unordered_map<int, int> map;
        map.emplace(0,1);
        int res = 0;
        for (auto sum : prefixSum) {
            if (map.count(sum - k)){
                res += map[sum-k];
            }
            map[sum]++;
        }
        return res;
    }
};
