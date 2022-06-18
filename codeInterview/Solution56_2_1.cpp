#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
                map[num]++;
        }

        for (auto [k,v]:map) {
            if (v == 1)
                return k;
        }
        return -1;
    }

};

