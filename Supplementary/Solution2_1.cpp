#include <bits/stdc++.h>

using namespace std;

//补充题2. 圆环回原点问题
//牛客：https://www.nowcoder.com/questionTerminal/16409dd00ab24a408ddd0c46e49ddcf8?answerType=1&f=discussion
class Solution {
public:
    int circle(int n) { //求走n步回到原点的方法数
        int mod = 1000000007; //结果可能特别大，要对mod取余
        int K = 10;  //圆环上有10个点，编号为[0,9]

        //dp[i][j]表示走i步到点编号为j的点有多少种方法
        vector<vector<int>> dp(n + 1, vector<int>(K));

        //base case
        dp[0][0] = 1;
        for (int j = 1; j < K; ++j) {
            dp[0][j] = 0;
        }


        //状态转移
        //dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
        //因为题目是环，这里用的数组，所以要处理j-1，j+1越界问题
        //故 dp[i][j] = dp[i-1][(j-1+K)%K] + dp[i-1][(j+1)%K]
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < K; ++j) {
                dp[i][j] = (dp[i - 1][(j - 1 + K) % K] + dp[i - 1][(j + 1) % K] ) % mod;
            }
        }

//        //for test
//        for (int i = 0; i <= n; ++i) {
//            for (int j = 0; j < K; ++j) {
//                cout << dp[i][j] << " ";
//            }
//            cout <<endl;
//        }
//        //

        return dp[n][0];
    }
};

int main(){
    Solution().circle(3);
}