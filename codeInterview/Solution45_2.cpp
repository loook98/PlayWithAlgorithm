#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //比较举例：s1="30",s2="3"
    //303 < 330 【字典序比较】
    static bool comp(const string& s1, const string& s2){
        return s1+s2 < s2+s1;
    }

    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), comp);

        string res;
        for (string str : strs) {
            res += str;
        }
        return res;
    }
};