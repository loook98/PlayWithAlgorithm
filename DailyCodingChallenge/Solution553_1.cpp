#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ret;
        for (int i = 0; i < nums.size(); ++i) {
            ret += to_string(nums[i]);
            if (i != nums.size() - 1){
                ret.push_back('/');
                if (i == 0 && nums.size() > 2)
                    ret.push_back('(');
            } else if (nums.size() > 2){
                ret.push_back(')');
            }
        }
        return ret;
    }
};