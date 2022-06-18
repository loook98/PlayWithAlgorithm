#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int index = 0;
        while (index < s.size()){
            //处理|
            for (int i = 0; index < s.size() && i < numRows; ++i) {
                rows[i].push_back(s[index++]);
            }
            //处理/
            for (int i = numRows - 2; index < s.size() && i > 0; --i) {
                rows[i].push_back(s[index++]);
            }
        }

        //合并结果
        string ret;
        for (int i = 0; i < numRows; ++i) {
            ret += rows[i];
        }
        return ret;
    }
};