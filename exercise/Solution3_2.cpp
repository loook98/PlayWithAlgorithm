#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1)
            return n;

        //滑动窗口[l,r)
        int l = 0, r = 0;
        unordered_map<char, int> map;
        int res = 0;
        while (r < n) {
            char c = s[r];
            r++;
            map[c]++;
            if (map[c] <= 1)
                res = max(res, r - l);
            while (map[c] > 1) {
                map[s[l]]--;
                l++;
            }
        }

        return res;
    }
};