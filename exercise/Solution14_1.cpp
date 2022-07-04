#include <bits/stdc++.h>

using namespace std;

//横向比较
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string curCommonPrefix = strs[0];

        for (int i = 1; i < n; ++i) {
            int indexCur = 0, indexStr = 0;
            while (indexCur < curCommonPrefix.size()) {
                if (indexStr >= strs[i].size()) {
                    curCommonPrefix = strs[i].substr(0, strs[i].size());
                    break;
                }

                if (curCommonPrefix[indexCur] != strs[i][indexStr]) {
                    curCommonPrefix = curCommonPrefix.substr(0, indexCur);
                    break;
                }

                indexCur++;
                indexStr++;
            }
        }

        return curCommonPrefix;
    }
};
