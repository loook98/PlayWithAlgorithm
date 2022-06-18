#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;//[left...right)为窗口
        int res = 0;
        while (right < s.size()){
            char c1 = s[right];
            right++;
            window[c1]++;

            while (window[c1] > 1){
                char c2 = s[left];
                left++;
                window[c2]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};