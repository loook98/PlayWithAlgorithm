#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> wordsFreq(words.size(), vector<bool>(26, false));
        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            for (const char& c : word) {
                wordsFreq[i][c-'a'] = true;
            }
        }

        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                int product = words[i].size() * words[j].size();
                if (product < ret)
                    continue;
                bool hasSameChar = false;
                for (int k = 0; k < 26; ++k) {
                    if (wordsFreq[i][k] && wordsFreq[j][k]){
                        hasSameChar = true;
                        break;
                    }
                }
                if (!hasSameChar &&
                    (product > ret))
                    ret = product;
            }
        }
        return ret;
    }
};