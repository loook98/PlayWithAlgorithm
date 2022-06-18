#include <bits/stdc++.h>

using namespace std;

//O(2n * 26)
class Solution {
public:
    int dfs(const string &s, int left, int right, int k) {
        if (left > right)
            return 0;

        vector<int> freq(26, 0);
        for (int i = left; i <= right; ++i) {
            freq[s[i] - 'a']++;
        }

        int split;
        for (split = 0; split < 26; ++split) {
            //如果有可以分割的字符
            if (freq[split] > 0 && freq[split] < k)
                break;
        }
        //没有可分割的字符
        if (split == freq.size())
            return right - left + 1;

        int splitChar = 'a' + split;
        int newL = left;
        int maxLen = 0;
        for (int i = left; i <= right; ++i) {
            if (s[i] != splitChar){
                continue;
            } else{
                int temp = dfs(s, newL, i-1, k);
                newL = i + 1;
                maxLen = max(maxLen, temp);
            }
        }
        //处理最后一个位置分割点后边的子串
        if (newL <= right){
            int temp = dfs(s, newL, right, k);
            maxLen = max(maxLen, temp);
        }
        return maxLen;
    }

    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }
};