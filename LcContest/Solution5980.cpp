#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;

        int subSz = 0;
        string  subStr;
        for (int i = 0; i < s.size(); ++i) {
            if (subSz == k){
                ret.emplace_back(subStr);
                subStr = "";
                subSz = 0;
            }
            subStr.push_back(s[i]);
            subSz++;
        }

        if (subSz > 0 && subSz <= k){
            for (int i = 0; i < k-subSz; ++i) {
                subStr.push_back(fill);
            }
            ret.emplace_back(subStr);
        }
        return ret;
    }
};