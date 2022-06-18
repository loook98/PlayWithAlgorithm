#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        unordered_map<char, int> freqTarget;
        for (auto c : target) {
            freqTarget[c]++;
        }

        int n = target.size();
        vector<int> candidate;

        for (int i = 0; i < n; ++i) {
            if (!freq.count(target[i]))
                return 0;
            else
                candidate.push_back(freq[target[i]] / freqTarget[target[i]]);
        }

        int res = INT32_MAX;
        for (int i = 0; i < candidate.size(); ++i) {
            res = min(res, candidate[i]);
        }

        return res;
    }
};