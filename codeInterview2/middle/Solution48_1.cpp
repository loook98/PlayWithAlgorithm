#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0, right = 0; //滑动窗口[left,right)

        unordered_set<char> chSet;
        int res = 0;
        while (right < n){
            char ch = s[right];
            right++;
            if (chSet.empty() || !chSet.count(ch)){
                chSet.insert(ch);
                res = max(res, right - left);
                continue;
            }

            while (!chSet.empty() && chSet.find(ch) != chSet.end()){
                chSet.erase(s[left]);
                left++;
            }
            chSet.insert(ch);
        }

        return res;
    }
};