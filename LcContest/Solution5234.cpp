#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> wordFreq(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (auto c: words[i]) {
                wordFreq[i][c - 'a']++;
            }
        }

        vector<string> res;
        res.push_back(words[0]);
        int lastIndex = 0;
        for (int i = 1; i < n; ++i) {
            bool needAdd = false; //不是异位，则需要加入res
            for (int j = 0; j < 26; ++j) {
                if (wordFreq[lastIndex][j] != wordFreq[i][j]){
                    needAdd = true;
                    break;
                }
            }
            if (needAdd){
                res.push_back(words[i]);
                lastIndex = i;
            }
        }

        return res;
    }
};