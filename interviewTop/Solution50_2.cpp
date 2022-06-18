#include <bits/stdc++.h>

using namespace std;

//快速幂，分治思路
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0f)
            return 0.0f;
        long long bigN = n;
        if (bigN < 0){
            x = 1.0/x;
            bigN = -bigN;
        }

        double res = 1.0;
        while (bigN > 0){
            if ((bigN & 1) == 1)
                res *= x;
            x *= x;
            bigN = bigN >> 1;
        }
        return res;
    }
};