#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        //dp[i][j]表示将word1[0,i-1]转化为word2[0, j-1]的最少步骤数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        //base case
        for (int i = 0; i < m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = j;
        }

        //状态转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) +  1;
                }
            }
        }

        return dp[m][n];
    }
};