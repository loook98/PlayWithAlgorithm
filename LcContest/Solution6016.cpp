#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1 = s[0], r1 = s[1];
        int c2 = s[3], r2 = s[4];

        vector<string> ret;
        for (int j = c1; j <= c2; ++j) {
            for (int i = r1; i <= r2; ++i) {
                string s;
                s.push_back(j);
                s.push_back(i);
                ret.push_back(s);
            }
        }
        return ret;
    }
};