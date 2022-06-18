#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //倒序dp
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];

        for (int i = n-2; i >= 0; --i) {
            int next = i + questions[i][1] + 1;
            dp[i] = max(dp[i+1], questions[i][0] + (next < n ? dp[next] : 0));
        }
        return dp[0];
    }
};