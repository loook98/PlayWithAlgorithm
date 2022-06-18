#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //左规则:当ratings[i]大于ratings[i-1]时，他的糖果要比左边的多。
    //右规则：当ratings[i]大于ratings[i+1]时，他的糖果要比右边的多。
    //每个孩子的的左规则和右规则的最大值就是这个孩子需要分的最少糖果。
    int candy(vector<int> &ratings) {
        int n = ratings.size();

        vector<int> leftRule(n, 1);
        vector<int> rightRule(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                leftRule[i] = leftRule[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rightRule[i] = rightRule[i + 1] + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += max(leftRule[i], rightRule[i]);
        }
        return res;
    }
};