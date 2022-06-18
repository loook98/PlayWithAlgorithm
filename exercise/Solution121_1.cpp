#include <bits/stdc++.h>

using namespace std;

//贪心
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        vector<int> rightMax(n); //rightMax[i]表示prices[i...n)中最大的元素
        rightMax[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(prices[i], rightMax[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, rightMax[i + 1] - prices[i]);
        }
        return res;
    }
};