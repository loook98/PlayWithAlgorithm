#include <bits/stdc++.h>

using namespace std;

//错误解法
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];
        vector<long long> maxDp(n, 0);
        maxDp[n-1] = questions[n-1][0];

        long long ret = dp[n-1];
        for (int i = n-2; i >= 0; --i) {
            int next = i + questions[i][1] + 1;
            if (next < n){
                //这里+的不一定是next，也可能是next以后的。。。。
                //dp[i] = questions[i][0] +dp[next];
                //下边这样就是n^2了,会超时
//                for (int j = next; j < n; ++j) {
//                    dp[i] = max(dp[i], questions[i][0] +dp[j]);
//                }
                dp[i] = questions[i][0] + maxDp[next];
            } else{
                dp[i] = questions[i][0];
            }
            if (dp[i] > ret){
                ret = dp[i];
            }
            if (maxDp[i] < maxDp[i+1])
                maxDp[i] = maxDp[i+1];
        }
        return ret;
    }
};