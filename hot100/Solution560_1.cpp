#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //暴力会超时
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum;
                if (i == 0)
                    sum = prefixSum[j];
                else
                    sum = prefixSum[j] - prefixSum[i-1];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};