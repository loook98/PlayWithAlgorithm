#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size();
        int l = n - 1, r = n - 1; //l,r找到一个单词的第一个词和最后一个词 (l..r]
        while (l >= 0) {
            if (s[l] == ' ')
                l--;
            else {
                r = l;//找到了单词的右界限
                while (l >= 0 && s[l] != ' ') {
                    l--;
                }
                res += s.substr(l + 1, r - l) + " ";
            }
        }
        res.pop_back();
        return res;
    }
};