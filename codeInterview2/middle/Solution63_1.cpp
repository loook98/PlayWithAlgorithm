#include <bits/stdc++.h>

using namespace std;

//记录当前位置之前的最小股票价格
//在每个位置计算当前卖出的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMin = INT32_MAX;
        int res = 0;
        for (int price : prices) {
            res = max(res, price - preMin);
            preMin = min(preMin, price);
        }

        return res;
    }
};