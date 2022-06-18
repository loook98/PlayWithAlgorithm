#include <bits/stdc++.h>

using namespace std;

//用hash的方法优化暴力解法
class Solution {
public:
    const long long MOD = (long long) (1e9 + 1);

    string longestPrefix(string s) {
        // pow[i] : 26^i
        long long pow[s.size()];
        pow[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            pow[i] = (pow[i - 1] * 26) % MOD;
        }

        // preHash[i]:  hash(s[0...i])
        long long preHash[s.size()];
        preHash[0] = s[0] - 'a';
        for (int i = 1; i < s.size(); ++i)
            preHash[i] = (preHash[i - 1] * 26 + s[i] - 'a') % MOD;

        //postHash[i]: hash(s[i...s.size()-1])
        long long postHash[s.size()];
        postHash[s.size() - 1] = s[s.size() - 1] - 'a';
        for (int i = s.size() - 2; i >= 0; --i)
            postHash[i] = ((s[i] - 'a') * (pow[s.size() - 1 - i + 1 - 1]) + postHash[i + 1]) % MOD;



        // s[0...len-1] ~ s[s.size()-len...s.size()-1]
        for (int len = s.size() - 1; len >= 1; --len) {
            if (preHash[len - 1] == postHash[s.size() - len] && equal(s, 0, len - 1, s.size() - len, s.size() - 1))
                return s.substr(0, len);
        }
        return "";
    }

    bool equal(string &s, int l1, int r1, int l2, int r2) {
        for (int i = l1, j = l2; i <= r1; ++i, ++j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};