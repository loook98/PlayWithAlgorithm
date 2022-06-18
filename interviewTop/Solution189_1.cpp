#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //先反转整个数组，然后再反转前k个，再反转后n-k个。
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
    }
};