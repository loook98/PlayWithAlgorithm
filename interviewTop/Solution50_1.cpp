#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //快速幂,二进制表示思路
    double myPow(double x, int n) {
        int absN = abs(n);
        if (x == 1.0)
            return 1.0;
        if (absN == 0)
            return 1.0;
        double res = 1.0, xn;
        bool first = true;
        while (absN > 0) {
            if (first) {
                xn = x;
                first = false;
            } else
                xn = xn * xn;

            if ((absN & 1) == 1)
                res *= xn;
            absN = absN >> 1;
        }
        if (n < 0)
            return 1.0 / res;
        else
            return res;
    }
};