#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window; //注意：window中只记录need中出现的元素
        for (char c: t) {
            need[c]++;
        }

        int resStart = 0, resLen = INT32_MAX;
        int validNum = 0; //记录窗口中已经满足条件的字符数
        //滑动窗口为[l,r)
        int l = 0, r = 0;
        while (r < s.size()) {
            char ch = s[r];
            r++;

            if (need.count(ch)){  //这个if不能没有
                window[ch]++;
                if (window[ch] == need[ch]) {
                    validNum++;
                }
            }


            while (validNum == need.size()) {
                if (r - l < resLen) {
                    resStart = l;
                    resLen = r - l;
                }

                char c = s[l];
                l++;
                if (need.count(c)){
                    window[c]--;
                    if (window[c] < need[c]) {
                        validNum--;
                    }
                }
            }
        }

        return resLen == INT32_MAX ? "" : s.substr(resStart, resLen);
    }
};