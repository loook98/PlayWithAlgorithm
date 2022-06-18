#include <bits/stdc++.h>

using namespace std;

//对方法1的整型溢出的处理
//从n到1，统计各个5的倍数可以贡献几个5，求出5因子的个数。
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int divisor = n; divisor / 5 > 0; divisor = divisor / 5) {
            res += divisor / 5;
        }
        return res;
    }
};