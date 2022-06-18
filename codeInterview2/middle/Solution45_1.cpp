#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(int num1, int num2) {
        string s1 = to_string(num1) + to_string(num2);
        string s2 = to_string(num2) + to_string(num1);
        return s1 < s2;
    }

    string minNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};