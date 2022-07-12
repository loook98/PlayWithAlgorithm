#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetMap;
        for (auto &c: t) {
            targetMap[c]++;
        }

        string res;
        unordered_map<char, int> windowMap;
        int matchNum = 0; //滑动窗口中数量>=target中的字符的个数
        //滑动窗口为[l,r)
        int l = 0, r = 0;
        while (r < s.size()) {
            char ch = s[r];
            r++;
            if (targetMap.find(ch) != targetMap.end()){
                windowMap[ch]++;
                if (windowMap[ch] == targetMap[ch])
                    matchNum++;
            }

            while (matchNum == targetMap.size()){
                if (res.empty() || r - l < res.size()){
                    res = s.substr(l, r - l);
                }

                char ch2 = s[l];
                l++;
                if (targetMap.find(ch2) != targetMap.end()){
                    if (windowMap[ch2] == targetMap[ch2])
                        matchNum--;
                    windowMap[ch2]--;
                }
            }
        }

        return res;
    }
};