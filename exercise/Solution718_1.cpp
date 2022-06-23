#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        //dp[i][j]表示以nums1以i-1结尾 和 nums2以j-1结尾的最长重复子数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        //base case dp[0][...] dp[...][0] = 0

        int res = 0;
        //状态转移
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                // else = 0

                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};