#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string largestNumber(vector<int> &nums) {
        auto cmp = [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        };
        vector<string> numsStr(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            numsStr[i] = to_string(nums[i]);
        }

        //对于两个数num1和num2, 「num1后边拼上num2」 > 「num2后边拼上num1」的话，num1应排在前边。
        sort(numsStr.begin(), numsStr.end(), cmp);

        string res;
        bool isPrefixZero = true; //用于去掉前导0
        for (int i = 0; i < numsStr.size(); ++i) {
            if (numsStr[i] != "0")
                isPrefixZero = false;
            if (!isPrefixZero || i == numsStr.size() - 1)
                res += numsStr[i];
        }

        return res;
    }
};