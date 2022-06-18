#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set; //记录nums中出现的数

        for (int &num: nums) {
            set.insert(num);
        }

        int res = 0;
        for (int &num: nums) {
            if (set.find(num - 1) != set.end())
                continue;

            int len = 0, curV = num;
            while (set.find(curV) != set.end()){
                len++;
                curV++;
            }

            res = max(res, len);
        }

        return res;
    }
};