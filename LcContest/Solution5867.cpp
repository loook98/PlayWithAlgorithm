#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1, n = word.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] == ch){
                index = i;
                break;
            }
        }
        if (index == -1)
            return word;

        int l = 0, r = index;
        while (l < r){
            swap(word[l],word[r]);
            l++;
            r--;
        }

        return word;
    }
};