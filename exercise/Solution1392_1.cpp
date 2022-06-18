#include <bits/stdc++.h>

using namespace std;

//暴力解法 遍历所有前缀，看等不等于后缀。 会超时
class Solution {
public:
    string longestPrefix(string s) {
        // s[0...len-1] ~ s[s.size()-len...s.size()-1]
        for (int len = s.size() - 1; len >= 1; --len) {
            if (equal(s, 0, len - 1, s.size() - len, s.size() - 1))
                return s.substr(0, len);
        }
        return "";
    }

    bool equal(string &s, int l1, int r1, int l2, int r2) {
        for (int i = l1, j = l2; i <= r1; ++i, ++j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};