#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> seq;
        int n = nums.size();
        for (auto num : nums) {
            ++seq[num];
            if (seq[num] > n / 2){
                return num;
            }
        }
        return -1;
    }
};