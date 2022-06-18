#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int freq[26] = {0};
        for (char ch: s) {
            freq[ch - 'a']++;
        }

        for (char c: s) {
            if (freq[c-'a'] == 1)
                return c;
        }
        return ' ';
    }
};
