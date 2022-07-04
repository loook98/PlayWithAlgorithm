#include <bits/stdc++.h>

using namespace std;

//牛顿迭代法
class Solution {
public:
    int a;

    int mySqrt(int x) {
        a = x;
        if (x == 0)
            return 0;
        return (int) newtonMethod(x);
    }

    double newtonMethod(double x) {
        double res = (x + a / x) / 2;

        if (res == x)
            return x;
        else
            return newtonMethod(res);
    }
};