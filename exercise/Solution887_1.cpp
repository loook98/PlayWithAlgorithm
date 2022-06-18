#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //error
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        //base case
        for (int i = 0; i < n + 1; ++i)
            dp[i][1] = i;
        for (int j = 0; j < k + 1; ++j)
            dp[0][j] = 0;


        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < k+1; ++j) {
                dp[i][j] = min(dp[i][j] , max(dp[i-1][j-1], dp[n-i][j]));
            }
        }

        return dp[n][k];
    }
};