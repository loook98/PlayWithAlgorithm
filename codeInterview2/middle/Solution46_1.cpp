#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();

        vector<int> dp(n + 1); //dp[i]时的字符对应s[i-1]
        //base case
        dp[0] = dp[1] = 1;

        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1];
            if (s[i-1-1] == '1' || (s[i-1-1] == '2' && s[i-1] <= '5'))
                dp[i] += dp[i-2];
        }

        return dp[n];
    }
};