#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {

        //dp[i][j]表示从strs[0...k]中选，放入容量为（m,n）的背包中，最多可以放几个
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //base case : dp[0][...]、dp[...][0] = 0

        //状态转移
        for (const string &str: strs) {
            int zeroNum = 0, oneNum = 0;
            for (const char &c: str) {
                if (c == '0')
                    zeroNum++;
                else
                    oneNum++;
            }

            for (int i = m; i >= zeroNum; --i) {
                for (int j = n; j >= oneNum; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};