#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        int absN = abs(n);
        double res = myQuickPow(x, absN);
        if (n < 0)
            res = 1/res;
        return res;
    }

    //递归的快速幂。指数必须为正数
    double myQuickPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;

        double sub = myQuickPow(x, n / 2);
        if (n & 1) { //奇数
            return x * sub * sub;
        } else{
            return sub * sub;
        }
    }
};