#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss;
        ss << sentence;
        int res = 0;
        string str;
        while (ss >> str) {
            if (isWord(str))
                res++;
        }
        return res;
    }

    bool isWord(string s) {
        int n = s.size();
        if (s[0] == '-' || s[n - 1] == '-')
            return false;
        bool hasHyphen = false;
        for (int i = 0; i < n; ++i) {
            if (isLetter(s[i]))
                continue;
            else if (s[i] == '-') {
                if (i > 0 && i < n) {
                    if (!isLetter(s[i - 1]) || !isLetter(s[i + 1]))
                        return false;
                }
                if (!hasHyphen)
                    hasHyphen = true;
                else
                    return false;
                continue;
            } else if (isPunctuation(s[i])) {
                if (i != n - 1)
                    return false;
                else
                    continue;
            } else
                return false;
        }
        return true;
    }

    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }

    bool isPunctuation(char c) {
        return c == '!' || c == '.' || c == ',';
    }
};
