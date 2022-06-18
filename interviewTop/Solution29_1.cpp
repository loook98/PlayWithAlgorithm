#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 1)
            return dividend;

        if (divisor == -1){
            if (dividend != INT32_MIN)
                return -dividend;
            else
                return INT32_MAX;
        }

        bool isNegative = true;
        if ((dividend > 0 && divisor > 0) ||
                (dividend < 0 && divisor < 0))
            isNegative = false;
        long long dividendL = dividend;
        long long divisorL = divisor;
        dividendL = dividendL > 0 ? dividendL : -dividendL;
        divisorL = divisorL > 0 ? divisorL : -divisorL;

        int res = div(dividendL, divisorL);
        if (isNegative)
            res = 0 - res;
        return res;
    }

    int div(long long dividend, long long divisor){
        if (divisor > dividend)
            return 0;

        int res = 1;
        long long tempDiv = divisor;
        while (tempDiv + tempDiv< dividend){
            res += res;
            tempDiv += tempDiv;
        }
        res += div(dividend - tempDiv, divisor);
        return res;
    }
};