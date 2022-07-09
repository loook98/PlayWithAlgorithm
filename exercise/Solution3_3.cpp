#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0; // [l,r)为滑动窗口
        unordered_map<char, int> window;
        int res = 0;

        while (r < s.size()){
            char ch = s[r++];
            window[ch]++;

            if (window[ch] <= 1)
                res = max(res, r - l);
            while (window[ch] > 1){
                window[s[l]]--;
                l++;
            }
        }

        return res;
    }
};