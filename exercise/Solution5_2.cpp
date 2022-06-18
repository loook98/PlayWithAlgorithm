#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            string tmp1 = odd(s, i);
            if (tmp1.size() > res.size())
                res = tmp1;
            string tmp2 = even(s, i);
            if (tmp2.size() > res.size())
                res = tmp2;
        }
        return res;
    }

    //找出以s[i]为中心的最长回文子串
    string odd(string &s, int i) {
        int l = i, r = i;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r])
                break;
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

    //找出以s[i]s[i+1]为中心的最长回文子串
    string even(string &s, int i) {
        if (i + 1 >= s.size())
            return "";
        int l = i, r = i + 1;
        while (l >= 0 && r < s.size()) {
            if (s[l] != s[r])
                break;
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};