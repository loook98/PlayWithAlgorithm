#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0)
            return "";
        string ret = "";

        int left = 0, right = 0;
        while (right < n){
            if (s[right] != ' '){
                right++;
            } else{
                for (int i = right - 1; i >= left ; --i) {
                    ret.push_back(s[i]);
                }
                ret.push_back(' ');

                right++;
                left = right;
            }
        }

        //处理最后一个单词
        for (int i = right - 1; i >= left ; --i) {
            ret.push_back(s[i]);
        }

        return ret;
    }
};