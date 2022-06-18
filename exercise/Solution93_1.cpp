#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        backtacking(s, 0, 0);
        return res;
    }

    void backtacking(string &s, int cur, int level) {
        if (level == 3) { //处理最后一个范围
            if (cur >= s.size() || s.size() - cur > 3)
                return;
            if (s[cur] == '0') {
                if (cur == s.size() - 1)
                    res.push_back(s);
            } else {
                if (stoi(s.substr(cur, s.size() - cur)) <= 255)
                    res.push_back(s);
                else
                    return;
            }
        }


        for (int j = 0; j < 3 && cur + j < s.size(); ++j) {
            int i = cur + j;
            if (stoi(s.substr(cur, j + 1)) > 255)
                break;

            s.insert(i + 1, ".");
            backtacking(s, i + 1 + 1, level + 1);
            s.erase(i + 1, 1);

            if (j == 0 && s[i] == '0')
                break;
        }
    }
};