#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        bucketSort(nums);
        for (auto num:nums) {
            cout << num << " ";
        }
        int n = nums.size();
        if(n < 2)
            return 0;
        int maxDif = nums[1] - nums[0];
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] > maxDif)
                maxDif = nums[i] - nums[i-1];
        }
        return maxDif;
    }

    void bucketSort(vector<int> &nums) {
        int c = 200; //每个桶中的最大容量



        int minV = INT32_MAX, maxV = INT32_MIN;
        for (auto e : nums) {
            minV = min(minV, e);
            maxV = max(maxV, e);
        }
        if(minV == maxV)
            return;

        int B = (maxV - minV + 1) / c + ((maxV - minV + 1) % c > 0 ? 1 : 0); //桶的个数，注意向上取整

        vector<list<int>> buckets(B);

        for (auto e : nums)
            buckets[(e - minV) / c].emplace_back(e);
        for (auto &bucket : buckets)
            bucket.sort();

        int index = 0;
        for (const auto& bucket : buckets)
            for (auto e : bucket)
                nums[index++] = e;
    }
};