#include <bits/stdc++.h>

using namespace std;

//滑动窗口用map记录
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0; //[left,right)为窗口
        int res = 0;
        while (right < s.size()){
            char ch = s[right];
            right++;

            //
            map[ch]++;
            //
            while (map[ch] > 1){
                map[s[left]]--;
                left++;
            }

            res = max(res, right - left);
        }
        return res;
    }
};