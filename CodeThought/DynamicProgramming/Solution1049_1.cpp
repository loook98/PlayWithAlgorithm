#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0;
        for (int &stone: stones) {
            sum += stone;
        }
        int half = sum / 2;

        vector<vector<int>> dp(stones.size(), vector<int>(half + 1, 0));
        //base case
        for (int j = stones[0]; j <= half; ++j) {
            dp[0][j] = stones[0];
        }

        //状态转移
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 1; j <= half; ++j) {
                if (stones[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]] + stones[i]);
            }
        }

        int another = sum - dp[stones.size()-1][half];

        return abs(another - dp[stones.size()-1][half]);
    }
};