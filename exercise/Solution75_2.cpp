#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //更一般化的计数排序
    void sortColors(vector<int> &nums) {
        //处理的取值范围时[0,r)的计数排序
        int R = 3;
        vector<int> cnt(R, 0);
        for (auto num : nums) {
            cnt[num]++;
        }

        vector<int> index(R + 1, 0);
        for (int i = 1; i < R + 1; ++i) {
            index[i] = index[i - 1] + cnt[i - 1];
        }

        for (int i = 0; i < R; ++i) {
            for (int j = index[i]; j < index[i + 1]; ++j) {
                nums[j] = i;
            }
        }
    }
};