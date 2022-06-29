#include <bits/stdc++.h>

using namespace std;

//快速幂
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        int absN = abs(n);
        bool isNegative = false;
        if (n < 0)
            isNegative = true;

        double half = myPow(x, absN / 2);
        double half2 = half * half;
        if (absN % 2 == 0) {
            if (isNegative)
                return 1 / half2;
            else
                return half2;
        } else {
            half2 *= x;
            if (isNegative)
                return  1 /half2;
            else
                return half2;
        }
    }
};