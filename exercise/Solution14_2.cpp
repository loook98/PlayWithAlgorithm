#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curPrefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            if (curPrefix == "" || strs[i] == "")
                return "";

            int index = 0;
            while (index < curPrefix.size() && index < strs[i].size()){
                if (curPrefix[index] != strs[i][index])
                    break;

                index++;
            }

            curPrefix = curPrefix.substr(0, index);
        }

        return curPrefix;
    }
};