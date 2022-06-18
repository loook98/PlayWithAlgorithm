#include <bits/stdc++.h>

using namespace std;

//2*5=10,2可以有偶数给出，所以就是求1...n中的各个数共可以提供多少个5.
// n/5 可以算出n的阶乘中有多少个5的倍数
// 而25可以提供2个5，上边的方法只记了一个5， 所以res要加上 n/25，即1...n中25的倍数的个数。
// 125可以提3个5， res 还要加上 n/25
// 依次类推直到 divisor>n

//有个问题，当n很大时，divisor可能会溢出
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long long divisor = 5;
        while (divisor <= n){
            res += n / divisor;
            divisor *= 5;
        }

        return res;
    }
};