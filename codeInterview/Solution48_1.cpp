#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        unordered_set<char> set;
        int l = 0, r = 0; //[l...r]表示滑动窗口的范围
        int res = 1;
        while (r < n) {
            if (!set.count(s[r])) {
                if (r - l + 1 > res)
                    res = r - l + 1;
                set.emplace(s[r]);
            } else {
                while (l < r) {
                    if (set.count(s[r])) {
                        set.erase(s[l]);
                        l++;
                    } else {
                        break;
                    }
                }
                set.emplace(s[r]);
            }
            r++;
        }
        return res;
    }
};
