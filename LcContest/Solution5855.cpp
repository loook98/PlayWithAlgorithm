#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(string s1, string s2) {
        if (s1.size() < s2.size())
            return true;
        else if (s1.size() > s2.size())
            return false;
        else {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] < s2[i])
                    return true;
                else if (s1[i] > s2[i])
                    return false;
            }
            //两个值相等
            return false;
        }
    }

    string kthLargestNumber(vector<string> &nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size() - 1 - (k - 1)];
    }
};
