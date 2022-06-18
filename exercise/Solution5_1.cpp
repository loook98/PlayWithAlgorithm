#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //寻找s中以[l,r]为中心的回文串
    string palindrome(const string& s, int l, int r){
        while (l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, (r-l-1));
    }

    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            string sOdd = palindrome(s, i, i);
            string sEven = palindrome(s, i, i + 1);

            if (sOdd.size() > res.size())
                res = sOdd;
            if (sEven.size() > res.size())
                res = sEven;
        }
        return res;
    }
};