#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> res;
        vector<int> evenIndexes;

        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i]%2 == 0)
                evenIndexes.emplace_back(i);
        }

        int num;
        for (auto evenI : evenIndexes) {
            for (int i = 0; i < digits.size(); ++i) {
                if (i == evenI)
                    continue;
                for (int j = 0; j < digits.size(); ++j) {
                    if (j == evenI || j == i || digits[j] == 0)
                        continue;
                    num = digits[j] * 100 + digits[i] * 10 + digits[evenI];
                    if (num > 99)
                        res.insert(num);
                }
            }
        }

        vector<int> ret(res.begin(), res.end());
        sort(ret.begin(), ret.end());
        return ret;
    }
};