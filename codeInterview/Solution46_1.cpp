#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int n = str.size();
        int dp[n + 1];
        dp[0] = 1, dp[1] = 1;
        int index;
        for (int i = 2; i <= n; ++i) { //dp的索引i
            index = i - 1;//str的索引时dp的索引-1
            dp[i] = dp[i - 1];
            if (str[index - 1] == '1' || (str[index - 1] == '2' && str[index] <= '5') )
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};