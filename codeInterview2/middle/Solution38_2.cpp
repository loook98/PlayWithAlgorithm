#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> permutation(string s) {
        subPermutation(s, 0);
        return res;
    }

    //确定s字符串的第i个位置的元素的可能选择
    void subPermutation(string &s, int index) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }

        set<char> hasSwapped;
        for (int i = index; i < s.size(); ++i) {
            if (hasSwapped.find(s[i]) != hasSwapped.end())
                continue;
            hasSwapped.insert(s[i]);

            swap(s[index], s[i]);
            subPermutation(s, index + 1);
            swap(s[index], s[i]);
        }
    }
};