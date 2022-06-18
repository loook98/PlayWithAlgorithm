#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> noteFq(26, 0);
        vector<int> mgzFq(26, 0);

        for (auto i : ransomNote) {
            noteFq[i - 'a']++;
        }
        for (auto i : magazine) {
            mgzFq[i - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (noteFq[i] > mgzFq[i])
                return false;
        }

        return true;
    }
};