#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            int l = i-k, r = i + k;
            if (l < 0 || r >= n){
                ret[i] = -1;
            }else{
                long long sum = prefixSum[i+k] - prefixSum[i-k] + nums[i-k];
                ret[i] = (sum / (2 * k + 1));
            }
        }

        return ret;
    }
};