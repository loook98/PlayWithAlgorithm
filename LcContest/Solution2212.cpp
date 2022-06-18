#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
        int n = aliceArrows.size();
        int maxScore = 0, maxState = 0;

        //state中的每一位代表这个区域bob是否获胜
        for (int state = 0; state < (1 << n); ++state) {
            int arrowNeed = 0;//这种状态需要使用的箭数
            int score = 0; //这种状态可以得到分数

            //计算arrowNeed和score
            int mask = 1;
            for (int i = 0; i < n; ++i) {
                if (state & mask){
                    arrowNeed += aliceArrows[i] + 1;
                    score += i;
                }
                mask <<= 1;
            }

            if (arrowNeed <= numArrows && score > maxScore){
                maxState = state;
                maxScore = score;
            }
        }

        //用maxState构造结果
        vector<int> res(n);
        int mask = 1;
        for (int i = 0; i < n; ++i) {
            if (maxState & mask){
                res[i] = aliceArrows[i] + 1;
                numArrows -= res[i];
            }
            mask <<= 1;
        }
        //将剩余的箭射到0区域
        res[0] += numArrows;

        return res;
    }
};