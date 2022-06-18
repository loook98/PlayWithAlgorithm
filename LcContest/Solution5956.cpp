#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &word){
        int n = word.size();
        int l= 0, r = n-1;
        while (l < r){
            if (word[l++] != word[r--])
                return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (auto word : words) {
            if (isPalindrome(word))
                return word;
        }
        return "";
    }
};