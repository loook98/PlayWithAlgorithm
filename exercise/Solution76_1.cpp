#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = -1; //滑动窗口为[left...right]
        int start = 0, len = INT32_MAX;
        int valid = 0;//表示窗口中符合条件的字符个数
        int n = s.size();
        while (right < n){
            right++;
            char c1 = s[right];
            if (need.count(c1)){
                window[c1]++;
                if (window[c1] == need[c1])
                    valid++;
            }

            while (valid == need.size()){
                //这里更新最小覆盖串
                if (right - left + 1 < len){
                    start = left;
                    len = right - left + 1;
                }

                char c2 = s[left];
                left++;
                if (need.count(c2)){
                    window[c2]--;
                    if (window[c2] < need[c2])
                        valid--;
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};