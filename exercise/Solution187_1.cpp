#include <bits/stdc++.h>

using namespace std;

//暴力方法。使用哈希表存储，遍历所有长度为10的子串
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;

        for (int i = 0; i + 9 < s.size(); ++i) {
            string str = s.substr(i,10);
            if (seen.count(str))
                res.insert(str);
            else
                seen.insert(str);
        }
        vector<string> ret(res.begin(), res.end());

        return ret;
    }
};