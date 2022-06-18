#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> set;//set中存放nums中出现过的数
        for (int num:nums) {
            set.insert(num);
        }

        int maxSeq = 1, seq;
        for (int num:nums) {
            if (set.count(num - 1))
                continue;
            seq = 1;
            while (set.count(num + 1)){
                seq++;
                num++;
            }
            if (seq > maxSeq)
                maxSeq = seq;
        }
        return maxSeq;
    }
};