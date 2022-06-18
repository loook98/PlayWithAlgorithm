#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp = max(dp, prices[i]-minPrice);
            if (prices[i] < minPrice)
                minPrice = prices[i];
        }
        return dp;
    }
};