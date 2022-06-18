#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>> &stockPrices) {
        int n = stockPrices.size();
        if (n == 1)
            return 0;
//        if (n == 2)
//            return 1;

        sort(stockPrices.begin(), stockPrices.end(),
             [](vector<int> &price1, vector<int> &price2) { return price1[0] < price2[0]; });

        int res = 1;
        pair<long, long> lastRate ={(stockPrices[1][1] - stockPrices[0][1]),
                           (stockPrices[1][0] - stockPrices[0][0])};

        for (int i = 2; i < n; ++i) {
            pair<long ,long> newRate = {(stockPrices[i][1] - stockPrices[i-1][1]),
                              (stockPrices[i][0] - stockPrices[i-1][0])};
            if (lastRate.first * newRate.second != lastRate.second * newRate.first){
                lastRate = newRate;
                res++;
            }
        }
        return res;
    }
};