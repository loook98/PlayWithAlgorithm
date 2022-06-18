#include <bits/stdc++.h>

using namespace std;

//6014. 构造限制重复的字符串
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (auto c:s) {
            freq[c - 'a']++;
        }

        string ret;
        while (true) {
            int i;
            for (i = 25; i >= 0; --i) {
                if (freq[i] == 0)
                    continue;
                if (freq[i] <= repeatLimit) {
                    ret.append(freq[i], 'a' + i);
                    freq[i] = 0;
                } else {
                    ret.append(repeatLimit, 'a' + i);
                    freq[i] -= repeatLimit;
                    int j;
                    for (j = 25; j >= 0; --j) {
                        if (freq[j] == 0 || j == i)
                            continue;
                        ret.append(1,'a' + j);
                        freq[j]--;
                        break;
                    }
                    if (j == -1)
                        return ret;
                }
                break;
            }
            if (i == -1)
                break;
        }
        return ret;
    }
};