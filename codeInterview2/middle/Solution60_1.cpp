#include <bits/stdc++.h>

using namespace std;

//错误解法
//结果s的范围为[n,n*6],并且其值是轴对称的。
//s[n]的初值为 「(1/6)^n」,往后每位增加「(1/6)^n」,到中点后又开始每位减少「(1/6)^n」，直到最后减为「(1/6)^n」
class Solution {
public:
    vector<double> dicesProbability(int n) {
        double base = pow((1.0 / 6.0), n);
        int sz = n * 6 - n + 1;
        vector<double> res(sz, base);
        if (n == 1)
            return res;

        int mid = (sz - 1) / 2;
        int index = 1;
        while (index <= mid) {
            res[index] = res[index - 1] + base;
            index++;
        }
        if ((sz & 1) == 0) { //偶数个
            res[index] = res[index - 1];
            index++;
        }
        while (index < sz) {
            res[index] = res[index - 1] - base;
            index++;
        }
        return res;
    }
};