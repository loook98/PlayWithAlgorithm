#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            bool find = false;
            for (int l = i; l >= 0 && l >= i - k; --l) {
                if (nums[l] == key){
                    res.push_back(i);
                    find = true;
                    break;
                }
            }
            for (int r = i; !find && r < nums.size() && r <= i + k; ++r) {
                if (nums[r] == key){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};