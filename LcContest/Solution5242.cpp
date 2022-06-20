#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lowercase(26, false);
        vector<bool> capital(26, false);

        for (char & c : s) {
            if (c >= 'a' && c<= 'z')
                lowercase[c-'a'] = true;
            else
                capital[c-'A'] = true;
        }

        for (int i = 25; i >= 0 ; --i) {
            if (lowercase[i] && capital[i]){
                string s;
                s.push_back('A' + i);
                return s;
            }
        }

        return "";
    }
};